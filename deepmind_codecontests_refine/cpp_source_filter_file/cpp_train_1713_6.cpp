#include <bits/stdc++.h>
int a[100009];
int S[100009];
struct sLine {
  int K, B;
  int L, R;
} lines[2000009];
int linesCnt;
struct sTree {
  int l, r;
  sLine* arr;
  int pl, pr;
  int cnt;
} tree[200009];
int treeSize;
int BuildTree(int l, int r) {
  int cur = treeSize++;
  tree[cur].l = l;
  tree[cur].r = r;
  if (l < r) {
    tree[cur].pl = BuildTree(l, (l + r) / 2);
    tree[cur].pr = BuildTree((l + r) / 2 + 1, r);
    tree[cur].arr = &lines[linesCnt];
    int i = 0, j = 0;
    int lCnt = tree[tree[cur].pl].r - tree[tree[cur].pl].l + 1;
    int rCnt = tree[tree[cur].pr].r - tree[tree[cur].pr].l + 1;
    for (int k = 0; k < r - l + 1; k++) {
      if (i < lCnt &&
          (j >= rCnt ||
           (tree[tree[cur].pl].arr[i].K > tree[tree[cur].pr].arr[j].K ||
            (tree[tree[cur].pl].arr[i].K == tree[tree[cur].pr].arr[j].K &&
             tree[tree[cur].pl].arr[i].B < tree[tree[cur].pr].arr[j].B))))
        tree[cur].arr[k] = tree[tree[cur].pl].arr[i++];
      else
        tree[cur].arr[k] = tree[tree[cur].pr].arr[j++];
    }
    linesCnt += lCnt + rCnt;
  } else {
    tree[cur].arr = &lines[l];
  }
  return cur;
}
void BuildCH(int cur) {
  int j = 1;
  for (int k = 1; k < tree[cur].r - tree[cur].l + 1; k++) {
    if (tree[cur].arr[k].K == tree[cur].arr[k - 1].K) continue;
    int intersect = -1;
    while (j) {
      intersect = (tree[cur].arr[j - 1].B - tree[cur].arr[k].B) /
                  (tree[cur].arr[k].K - tree[cur].arr[j - 1].K);
      if (intersect >= tree[cur].arr[j - 1].L) break;
      j--;
      intersect = -1;
    }
    if (j) {
      tree[cur].arr[j - 1].R = intersect;
    }
    tree[cur].arr[j] = tree[cur].arr[k];
    tree[cur].arr[j].L = intersect + 1;
    j++;
  }
  tree[cur].cnt = j;
  if (tree[cur].l < tree[cur].r) {
    BuildCH(tree[cur].pl);
    BuildCH(tree[cur].pr);
  }
}
int Find(int X, int cur) {
  int l = 0, r = tree[cur].cnt - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (tree[cur].arr[m].L <= X && X <= tree[cur].arr[m].R)
      return tree[cur].arr[m].K * X + tree[cur].arr[m].B;
    if (X < tree[cur].arr[m].L)
      r = m - 1;
    else
      l = m + 1;
  }
}
int calcAns(int l, int r, int cur) {
  if (l <= tree[cur].l && r >= tree[cur].r) return Find(l - 1, cur);
  int ans = 100000000;
  if (l <= tree[tree[cur].pl].r && tree[tree[cur].pl].l <= r) {
    int tmp = calcAns(l, r, tree[cur].pl);
    if (ans > tmp) ans = tmp;
  }
  if (l <= tree[tree[cur].pr].r && tree[tree[cur].pr].l <= r) {
    int tmp = calcAns(l, r, tree[cur].pr);
    if (ans > tmp) ans = tmp;
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    S[i] = S[i - 1] + a[i];
    linesCnt++;
    lines[linesCnt].K = -a[i];
    lines[linesCnt].B = a[i] * i - S[i];
    lines[linesCnt].L = 0;
    lines[linesCnt].R = 100000000;
  }
  int root = BuildTree(1, n);
  BuildCH(root);
  int m;
  scanf("%d", &m);
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", S[y] + calcAns(y - x + 1, y, root));
  }
}

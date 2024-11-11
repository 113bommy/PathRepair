#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
char s[MAXN];
int n;
char com[MAXN];
int treeMax[4 * MAXN];
int treeMin[4 * MAXN];
int lazy[4 * MAXN];
void upd(int i, int l, int r, int x, int y, int val) {
  if (l >= x && r <= y) {
    lazy[i] += val;
    treeMax[i] += val;
    treeMin[i] += val;
    return;
  }
  if (l > y || r < x) return;
  if (lazy[i] > 0) {
    upd(i * 2 + 1, l, (l + r) / 2, l, (l + r) / 2, lazy[i]);
    upd(i * 2 + 2, (l + r) / 2 + 1, r, (l + r) / 2 + 1, r, lazy[i]);
    lazy[i] = 0;
  }
  upd(i * 2 + 1, l, (l + r) / 2, x, y, val);
  upd(i * 2 + 2, (l + r) / 2 + 1, r, x, y, val);
  treeMax[i] = max(treeMax[i * 2 + 1], treeMax[i * 2 + 2]);
  treeMin[i] = min(treeMin[i * 2 + 1], treeMin[i * 2 + 2]);
}
bool balanced() {
  int l, r;
  l = 0;
  r = n - 1;
  int i = 0;
  while (l < r) {
    if (lazy[i]) {
      upd(i * 2 + 1, l, (l + r) / 2, l, (l + r) / 2, lazy[i]);
      upd(i * 2 + 2, (l + r) / 2 + 1, r, (l + r) / 2 + 1, r, lazy[i]);
      lazy[i] = 0;
    }
    i = i * 2 + 2;
    l = (l + r) / 2 + 1;
  }
  return treeMax[i] == 0 && treeMin[0] == 0;
}
int solve() {
  if (balanced())
    return treeMax[0];
  else
    return -1;
}
int main() {
  scanf("%d", &n);
  scanf("%s", com);
  int ind = 0;
  for (int i = 0; i < n; i++) {
    if (com[i] == 'R') {
      ind++;
    } else if (com[i] == 'L') {
      ind--;
      if (ind < 0) ind = 0;
    } else {
      char bef = s[ind];
      s[ind] = com[i];
      int befVal = 0;
      int curVal = 0;
      if (bef == '(')
        befVal = 1;
      else if (bef == ')')
        befVal = -1;
      if (s[ind] == '(')
        curVal = 1;
      else if (s[ind] == ')')
        curVal = -1;
      upd(0, 0, n - 1, ind, n - 1, curVal - befVal);
    }
    printf("%d\n", solve());
  }
}

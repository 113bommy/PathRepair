#include <bits/stdc++.h>
using namespace std;
struct node {
  long long sum[5];
  int num;
};
int n, i, j;
int en;
int vale[100005];
int val[100005];
node tree[30005];
long long answer;
char in[100005][10];
void init(int numnode, int treefrom, int treeto) {
  int ii;
  tree[numnode].num = 0;
  for (ii = 0; ii < 5; ii++) {
    tree[numnode].sum[ii] = 0;
  }
  if (treefrom == treeto) return;
  int treemid = (treefrom + treeto) / 2;
  init(numnode * 2, treefrom, treemid);
  init(numnode * 2 + 1, treemid + 1, treeto);
  return;
}
void update1(int numnode, int treefrom, int treeto, int pos) {
  if (treefrom == treeto) {
    tree[numnode].num = 1;
    tree[numnode].sum[0] = vale[pos];
    return;
  } else {
    int treemid = (treefrom + treeto) / 2;
    if (treemid >= pos) {
      update1(numnode * 2, treefrom, treemid, pos);
    } else {
      update1(numnode * 2 + 1, treemid + 1, treeto, pos);
    }
    tree[numnode].num = tree[numnode * 2].num + tree[numnode * 2 + 1].num;
    int ii;
    for (ii = 0; ii < 5; ii++) {
      tree[numnode].sum[(tree[numnode * 2].num + ii) % 5] =
          tree[numnode * 2].sum[(tree[numnode * 2].num + ii) % 5] +
          tree[numnode * 2 + 1].sum[ii];
    }
    return;
  }
}
void update2(int numnode, int treefrom, int treeto, int pos) {
  if (treefrom == treeto) {
    tree[numnode].num = 0;
    tree[numnode].sum[0] = 0;
    return;
  } else {
    int treemid = (treefrom + treeto) / 2;
    if (treemid >= pos) {
      update2(numnode * 2, treefrom, treemid, pos);
    } else {
      update2(numnode * 2 + 1, treemid + 1, treeto, pos);
    }
    tree[numnode].num = tree[numnode * 2].num + tree[numnode * 2 + 1].num;
    int ii;
    for (ii = 0; ii < 5; ii++) {
      tree[numnode].sum[(tree[numnode * 2].num + ii) % 5] =
          tree[numnode * 2].sum[(tree[numnode * 2].num + ii) % 5] +
          tree[numnode * 2 + 1].sum[ii];
    }
    return;
  }
}
int main() {
  scanf("%d", &n);
  en = 0;
  for (i = 0; i < n; i++) {
    scanf("%s", in[i]);
    if (in[i][0] == 'a' || in[i][0] == 'd') {
      scanf("%d", &val[i]);
      vale[en] = val[i];
      en++;
    }
  }
  sort(vale, vale + en);
  init(1, 0, en);
  for (i = 0; i < n; i++) {
    if (in[i][0] == 'a') {
      update1(1, 0, en, lower_bound(vale, vale + en, val[i]) - vale);
    } else if (in[i][0] == 'd') {
      update2(1, 0, en, lower_bound(vale, vale + en, val[i]) - vale);
    } else {
      cout << tree[1].sum[2];
      cout << '\n';
    }
  }
  return 0;
}

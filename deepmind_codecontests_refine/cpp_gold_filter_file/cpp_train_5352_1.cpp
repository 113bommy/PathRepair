#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int difcol[N], difpos[N], num[N], last[N], pos[N], far[N], ans[N], can[N];
vector<int> gr[N], ys[N];
int n, m;
int lowbit(int x) { return x & (-x); }
void add(int a, int* pArr, int v) {
  while (a <= n) {
    (*(pArr + a)) += v;
    a += lowbit(a);
  }
}
void add(int a, int b, int* pArr, int v) {
  add(a, pArr, v);
  add(b + 1, pArr, -v);
}
int getsum(int* pArr, int a) {
  int rev = 0;
  while (a) {
    rev += (*(pArr + a));
    a -= lowbit(a);
  }
  return rev;
}
void dealcan(int pos) {
  if (last[last[pos]]) {
    if ((last[last[pos]] - last[pos]) != (last[pos] - pos))
      can[pos] = 0;
    else
      can[pos] = 1;
  } else
    can[pos] = 1;
  if ((can[pos]) && (last[pos]))
    far[pos] = far[last[pos]];
  else
    far[pos] = last[last[pos]] + 1;
}
void work() {
  for (int i = 1; i <= n; i++) dealcan(i);
  for (int i = 1; i <= n; i++) {
    add(last[i] + 1, i, difcol, 1);
    add(last[i] + 1, i, difpos, 1);
    if (!can[i]) add(far[last[i]], last[last[i]], difpos, -1);
    for (int j = 0; j < gr[i].size(); j++) {
      int sumcol = getsum(difcol, gr[i][j]);
      int sumpos = getsum(difpos, gr[i][j]);
      if (sumpos)
        ans[ys[i][j]] = sumcol;
      else
        ans[ys[i][j]] = sumcol + 1;
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    last[i] = pos[num[i]];
    pos[num[i]] = i;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    gr[b].push_back(a);
    ys[b].push_back(i);
  }
  work();
  return 0;
}

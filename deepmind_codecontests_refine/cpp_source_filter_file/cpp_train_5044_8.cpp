#include <bits/stdc++.h>
using namespace std;
int arr[300005];
int n, m, q;
int ortu[300005];
int terjauh[300005];
int longest[300005];
vector<int> v[300005];
int find(int x) { return ortu[x] = (ortu[x] == x) ? x : find(ortu[x]); }
int x, y;
bool flag[300005];
void dfs(int now, int par, int depth) {
  if (depth > y) {
    x = now;
    y = depth;
  }
  flag[now] = true;
  int size = v[now].size();
  for (int i = 0; i < size; i++) {
    int next = v[now][i];
    if (next == par) continue;
    dfs(next, now, depth + 1);
  }
}
int sum = 0;
int center = 0;
int pcenter = 0;
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) ortu[i] = i;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
    ortu[find(a)] = find(b);
  }
  for (int i = 1; i <= n; i++) {
    if (flag[i]) continue;
    x = i;
    y = -1;
    dfs(i, -1, 0);
    y = -1;
    dfs(x, -1, 0);
    int jauh = (y + 1) / 2;
    int sekarang = find(i);
    terjauh[sekarang] = jauh;
    longest[sekarang] = y;
  }
  while (q--) {
    int op, a, b;
    scanf("%d", &op);
    if (op == 2) {
      scanf("%d %d", &a, &b);
      int para = find(a);
      int parb = find(b);
      if (para == parb) continue;
      int ta = terjauh[para];
      int la = longest[para];
      int tb = terjauh[parb];
      int lb = longest[parb];
      if (ta < tb) {
        ortu[para] = parb;
        longest[parb] = max(lb, tb + ta + 1);
        terjauh[parb] = max(tb, ta + 1);
      } else {
        ortu[parb] = para;
        longest[para] = max(la, ta + tb + 1);
        terjauh[para] = max(la, tb + 1);
      }
    } else {
      scanf("%d", &a);
      int para = find(a);
      printf("%d\n", longest[para]);
    }
  }
}

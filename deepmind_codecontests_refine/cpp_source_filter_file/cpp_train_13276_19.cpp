#include <bits/stdc++.h>
using namespace std;
struct Data {
  int x, y;
} par[100001];
int n, m, x, y, cnt;
int rnk[100001];
void make_set(int v) { par[v].x = v; }
int find_set(int v) {
  if (v == par[v].x) return v;
  return par[v].x = find_set(par[v].x);
}
void set_union(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b].x = a;
    if (par[a].y && par[b].y) par[b].y = 0;
    if (rnk[a] == rnk[b]) rnk[a]++;
  } else
    par[a].y = 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) make_set(i);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    set_union(x, y);
  }
  for (int i = 1; i <= n; i++)
    if (par[i].x == i)
      if (!par[i].y) cnt++;
  cout << cnt;
  return 0;
}

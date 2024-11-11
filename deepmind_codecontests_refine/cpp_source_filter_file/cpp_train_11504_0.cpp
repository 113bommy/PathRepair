#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010;
int n, m, u, v, x, y, typ, a, b, ans, tmp;
int par[MAXN];
set<int> st;
int get(int x) {
  if (par[x] == x) return x;
  return par[x] = get(par[x]);
}
void join(int x, int y) {
  if (get(x) > get(y)) swap(x, y);
  par[get(x)] = get(y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n + 1; i++) st.insert(i);
  for (int i = 1; i <= n + 1; i++) par[i] = i;
  while (m--) {
    cin >> typ >> x >> y;
    if (typ == 3) {
      if (get(x) == get(y))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
      continue;
    }
    if (typ == 1) {
      join(x, y);
      continue;
    }
    for (x = *st.lower_bound(x); x < y; x = *st.lower_bound(x)) {
      par[x] = y;
      st.erase(x);
    }
  }
  return 0;
}

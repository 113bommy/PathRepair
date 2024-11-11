#include <bits/stdc++.h>
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double EPS = 1e-10;
const long double PI = acos(-1);
const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int inf = 1e9;
const int MAXN = 1e3 + 1;
vector<int> g[MAXN];
int d[MAXN];
void dfs(int v, int p) {
  d[v] = d[p] + 1;
  for (int i : g[v]) {
    if (i != p) dfs(i, v);
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  srand(time(NULL));
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    fill(d, d + MAXN, 0);
    fill(g, g + MAXN, vector<int>(0));
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int k1;
    cin >> k1;
    int k2;
    vector<int> f1(k1);
    for (long long i = 0; i < f1.size(); ++i) cin >> f1[i];
    ;
    cin >> k2;
    vector<int> f2(k2);
    for (long long i = 0; i < f2.size(); ++i) cin >> f2[i];
    ;
    cout << "B " << f2[0] << endl;
    int x;
    cin >> x;
    dfs(x, x);
    int md = inf;
    int lol = 1;
    for (int i : f1)
      if (d[i] < md) {
        md = d[i], lol = i;
      }
    cout << "A " << lol << endl;
    cin >> x;
    if (count((f2).begin(), (f2).end(), x)) {
      cout << "C " << lol << endl;
      continue;
    } else {
      cout << -1 << endl;
    }
  }
}

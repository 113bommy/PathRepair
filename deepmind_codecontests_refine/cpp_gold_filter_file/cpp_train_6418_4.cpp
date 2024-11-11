#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const long long INF = 1e18;
const long long inf = 1e9;
const long double PI = acos(-1.0);
const long long mod1 = inf + 7;
const long long mod2 = inf + 9;
const long long MAXN = 200001;
const long double EPS = 1e-8;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> a(n);
  for (long long i = 0; i < a.size(); ++i) cin >> a[i];
  ;
  int nowsum = 0;
  sort((a).begin(), (a).end());
  reverse(a.begin(), a.end());
  ;
  int as = 0;
  for (int i = 0; i < a.size(); ++i) {
    as += a[i];
  }
  int ans = -as;
  for (int i = 0; i < a.size(); ++i) {
    nowsum += a[i];
    ans = max(ans, nowsum - (as - nowsum));
  }
  cout << ans;
}

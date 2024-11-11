#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const int inf = 1000000000 + 228;
const long double PI = acos(-1.0);
const long long mod1 = inf * inf + 1337 * 42 + 57 * 179 + 228;
const long long kekmod = 1000000000 + 7;
const long long mod2 = inf + 9;
const long long bigmod = 1LL * inf * 100 + 3;
const int MAXN = 100005;
const long double EPS = 1e-10;
const int N = 300228;
long long hp = 1e6 + 3;
signed main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  ;
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (long long i = 0; i < a.size(); i++) cin >> a[i];
  ;
  reverse(a.begin(), a.end());
  ;
  int sum = 0;
  for (int i = 0; i < k; ++i) {
    sum += min(a[i], k);
  }
  for (int i = k; i < n; ++i) {
    sum += a[i];
  }
  cout << sum;
}

#include <bits/stdc++.h>
using namespace std;
using VP = vector<pair<long long, long long> >;
using VVP = vector<VP>;
using VI = vector<long long>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
const int inf = 1e9 + 7;
const long long INF = 1LL << 58;
const long long mod = 1e9 + 7;
int main() {
  long long i, j;
  long long n;
  cin >> n;
  long long a[n + 1];
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  long long q;
  cin >> q;
  map<long long, long long> ma[n + 1];
  VI v(n + 1, 0);
  for (i = 0; i < q; i++) {
    long long s, t, u;
    scanf("%ld%ld%ld", &s, &t, &u);
    long long k = ma[s][t];
    if (k >= 1) {
      ans -= max(0ll, a[k] - v[k]);
      v[k]--;
      ans += max(0ll, a[k] - v[k]);
    }
    if (u >= 1) {
      ans -= max(0ll, a[u] - v[u]);
      v[u]++;
      ans += max(0ll, a[u] - v[u]);
    }
    ma[s][t] = u;
    printf("%ld\n", ans);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return R;
}
const int N = 500050;
const long long inf = 2e18;
long long dp[N], arr[N], arr2[N];
char str[N];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, k, a, b, t;
  long long sum = 0;
  string s;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a % b) {
      cout << a << endl;
      continue;
    }
    long long z = sqrtl(b);
    vector<pair<long long, long long> > v;
    n = b;
    for (int i = 2; i <= z; i++) {
      long long cn = 0;
      while (n % i == 0) {
        cn++;
        n /= i;
      }
      if (cn) v.push_back({i, cn});
    }
    if (n > 1) v.push_back({n, 1LL});
    vector<pair<long long, long long> > g;
    vector<long long> d;
    n = a;
    for (int i = 0; i < v.size(); i++) {
      long long cn = 0;
      while (n % v[i].first == 0) {
        cn++;
        n /= v[i].first;
      }
      if (cn >= v[i].second) {
        long long an = 1LL;
        for (long long j = 1; j <= cn - v[i].second + 1; j++) {
          an *= v[i].first;
        }
        d.push_back(an);
      }
    }
    if (d.size() == 0) {
      cout << (a / b) << endl;
    } else {
      sort(d.begin(), d.end());
      long long ans = (a / d[0]);
      cout << ans << endl;
    }
  }
  return 0;
}

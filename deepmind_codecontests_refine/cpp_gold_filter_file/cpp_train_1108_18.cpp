#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long double EPS = 1e11;
const long long INFL = 1e16;
const int INF = 1e9 + 7;
void mul(long long& a, long long b) { a = (a * b) % MOD; }
void add(long long& a, long long b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, r, k;
  cin >> n >> r >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<long long> def(n + r * 3 + 5, 0);
  for (int i = 0; i < n; ++i) {
    def[max(0LL, i - r)] += a[i];
    def[i + r + 1] -= a[i];
  }
  long long left = 0, righ = 1e18 + 1e16;
  while (righ - left > 1LL) {
    long long mid = (left + righ) / 2;
    vector<long long> dif(def);
    long long csp = k;
    long long act = 0;
    for (int i = 0; i < n; ++i) {
      act += dif[i];
      if (act < mid) {
        csp -= (mid - act);
        dif[i + 2 * r + 1] -= mid - act;
        act = mid;
        if (csp < 0LL) {
          break;
        }
      }
    }
    if (csp < 0) {
      righ = mid;
    } else {
      left = mid;
    }
  }
  cout << left << "\n";
  return 0;
}

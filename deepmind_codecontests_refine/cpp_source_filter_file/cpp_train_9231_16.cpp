#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long ar(long long n) { return (1 + n) * n / 2; }
const long double PI = 3.1415926;
const long long INF_LL = 1e18 + 7;
const long long Mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long n, vb, vs, ux, uy;
  cin >> n >> vb >> vs;
  vector<long long> a(n);
  for (long long i = 0; i < (n); ++i) cin >> a[i];
  cin >> ux >> uy;
  long double ans = 1e7;
  long long no = 0;
  for (long long i = 0; i < (n); ++i) {
    if (ans / ans * 1.0 * a[i] / vb +
                ans / ans * 1.0 * sqrt((ux - a[i]) * (ux - a[i]) + uy * uy) /
                    vs <
            ans &&
        i != 0) {
      ans = 1.0 * a[i] / vb +
            1.0 * sqrt((ux - a[i]) * (ux - a[i]) + uy * uy) / vs;
      no = i;
    }
  }
  cout << no + 1;
}

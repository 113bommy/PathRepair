#include <bits/stdc++.h>
using namespace std;
long long n, k, flag = 0;
const int N = 2e5 + 5;
long long A[N], B[N];
pair<long long, long long> T[N];
int main() {
  long long i, j, t, a, b, first, second = 0, c = 0, ans = 0, m;
  cin >> n >> t;
  long double d = 0, s = 0;
  for (i = 1; i <= n; i++) cin >> T[i].second, s += T[i].second;
  for (i = 1; i <= n; i++) cin >> T[i].first;
  sort(T + 1, T + n + 1);
  if (t > T[n].first || t < T[1].first) {
    cout << 0;
    return 0;
  }
  for (i = 1; i <= n; i++) {
    d = d + T[i].first * T[i].second;
  }
  if (d / s == (double)t) {
    cout << setprecision(6) << s;
    return 0;
  }
  if (d / s > t) {
    for (i = n; i >= 1; i--) {
      if ((d - T[i].first * T[i].second) / (s - T[i].second) <= t) break;
      d -= T[i].first * T[i].second;
      s -= T[i].second;
    }
    long double z = (s * t - d) / (t - T[i].first);
    cout << setprecision(6) << s - z;
  } else {
    for (i = 1; i <= n; i++) {
      if ((d - T[i].first * T[i].second) / (s - T[i].second) >= t) break;
      d -= T[i].first * T[i].second;
      s -= T[i].second;
    }
    long double z = (s * t - d) / (t - T[i].first);
    cout << setprecision(6) << s - z;
  }
}

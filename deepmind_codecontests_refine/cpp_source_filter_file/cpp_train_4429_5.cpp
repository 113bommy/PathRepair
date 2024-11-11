#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
bool cmin(A &a, const B &b) {
  return a > b ? (a = b, true) : false;
}
template <typename A, typename B>
bool cmax(A &a, const B &b) {
  return a < b ? (a = b, true) : false;
}
const double PI = acos(-1);
const double EPS = 1e-9;
long long inf = sizeof(long long) == sizeof(long long) ? 2e18 : 1e9 + 10;
long long dx[] = {0, 1, 0, -1};
long long dy[] = {1, 0, -1, 0};
signed main() {
  long long n, c;
  cin >> n >> c;
  vector<long long> s(n), t(n);
  for (long long i = 0; i < n; i++) cin >> s[i];
  for (long long i = 0; i < n; i++) cin >> t[i];
  long long sum1 = 0, sum2 = 0;
  long long t1 = 0, t2 = 0;
  for (long long i = 0; i < n; i++) {
    t1 += t[i], t2 += t[n - 1 - i];
    sum1 += max(0ll, s[i] - t1 * c);
    sum2 += max(0ll, s[n - 1 - i] - 2 * c);
  }
  if (sum1 == sum2)
    cout << "Tie" << endl;
  else if (sum1 > sum2)
    cout << "Limak" << endl;
  else
    cout << "Radewoosh" << endl;
}

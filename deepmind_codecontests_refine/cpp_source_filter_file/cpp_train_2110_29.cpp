#include <bits/stdc++.h>
using namespace std;
inline long long isqrt(long long k) {
  long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline long long mnz(long long& a, long long b) { return a = (a > b ? b : a); }
inline long long mxz(long long& a, long long b) { return a = (a < b ? b : a); }
inline string toString(long long n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
double const eps = 1e-6;
long long const Base = 1e9 + 7, oo = 1e17, MAXN = 1e6;
long long A[MAXN + 5];
long long Solves() {
  long long n, m, k, cnt = 0, ans = 0, x, y, q, c, sum = 0, v, t;
  cin >> n;
  for (long long i = 1; i <= n; i++) cout << 1e5 << " ";
  cout << "" << endl;
  return 0;
}
int main() {
  if (fopen("locin.txt", "r")) freopen("locin.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  cin >> test;
  for (long long T = 1; T <= test; T++) {
    Solves();
  }
}

#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool isLeap(T y) {
  return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false);
}
template <class T>
inline T gcd(T a, T b) {
  return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template <class T>
inline T lcm(T a, T b) {
  return ((a) / gcd((a), (b)) * (b));
}
template <class T>
inline T BigMod(T Base, T power, T M = 1000000007) {
  if (power == 0) return 1;
  if (power & 1)
    return ((Base % M) * (BigMod(Base, power - 1, M) % M)) % M;
  else {
    T y = BigMod(Base, power / 2, M) % M;
    return (y * y) % M;
  }
}
template <class T>
inline T ModInv(T A, T M = 1000000007) {
  return BigMod(A, M - 2, M);
}
int fx[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int fy[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool tri(long long b, long long c, long long d, long long e) {
  if ((b + c > e) || (b + d > e) || (c + d > e))
    return true;
  else
    return false;
}
bool seg(long long a, long long b, long long c, long long d) {
  if (a == b + c || a == c + d || a == b + d || b == a + c || b == c + d ||
      b == a + d || c == b + d || c == a + d || c == a + b || d == b + c ||
      d == c + a || d == b + a)
    return true;
  else
    return false;
}
int main() {
  long long n, m, k, mn = INT_MAX;
  cin >> n >> m >> k;
  vector<long long> v(n), l;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) {
    if (v[i] > 0 && v[i] <= k) l.push_back(i + 1);
  }
  for (int i = 0; i < l.size(); i++) {
    mn = min(mn, abs(l[i] - m));
  }
  cout << mn * 10 << endl;
}

#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e) {
  cout << e << '\n';
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << '\n';
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << '\n';
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << '\n';
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
ostream_iterator<int> screen(cout, " ");
const int sz = 2 * 1000 * 100 + 10, mod = 1000 * 1000 * 1000 + 7;
const int inf = INT_MAX >> 1;
const long long big = (1LL << 62);
const double pi = acos(-1.0);
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
vector<int> res;
long long powermod(long long n, long long p) {
  long long x = 1, y = n % mod;
  while (p) {
    if (p & 1LL) x = (y * x) % mod;
    y = (y * y) % mod;
    p = p >> 1LL;
  }
  return x;
}
int arr[3010];
int main() {
  std::ios_base::sync_with_stdio(false);
  string str;
  int ans = 0, r = -1, n;
  cin >> n;
  cin >> str;
  for (int i = 0; i < str.size(); i++) arr[i] = 1;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'L' and r == -1) {
      int j = i;
      while (j >= 0 and arr[j]) {
        arr[j]--;
        j--;
      }
    } else if (str[i] == 'L' and r > -1) {
      if ((i - r) % 2 == 1) ans++;
      for (int j = r; j <= i; j++) arr[j] = 0;
      r = -1;
    } else if (str[i] == 'R' and r > -1) {
      for (int j = r; j < i; j++) arr[j] = 0;
      r = i;
    } else if (str[i] == 'R')
      r = i;
  }
  if (r == -1) r = str.size();
  for (int i = 0; i < r; i++) ans += arr[i];
  cout << ans << endl;
  return 0;
}

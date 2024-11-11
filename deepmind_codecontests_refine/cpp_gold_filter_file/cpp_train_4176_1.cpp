#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& t) {
  return in >> t.first >> t.second;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& t) {
  return out << t.first << " " << t.second;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& t) {
  for (long long i = 0; i < t.size(); i++) in >> t[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& t) {
  for (long long i = 0; i < t.size(); i++) out << t[i] << " ";
  return out;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long rrrr = 1e9 + 1;
  long long n, m, k;
  cin >> n >> m >> k;
  if ((n * m * 2) % k != 0) return cout << "NO", 0;
  long long n1 = n / gcd(n, k);
  k /= gcd(n, k);
  long long m1 = m / gcd(m, k);
  k /= gcd(m, k);
  long long l = 2;
  l /= gcd(l, k);
  cout << "YES" << endl;
  cout << 0 << " " << 0 << endl;
  if (n1 * l <= n) {
    cout << 0 << ' ' << m1 << endl;
    cout << n1 * l << " " << 0 << endl;
  } else {
    cout << n1 << ' ' << 0 << endl;
    cout << 0 << " " << m1 * l << endl;
  }
  return 0;
}

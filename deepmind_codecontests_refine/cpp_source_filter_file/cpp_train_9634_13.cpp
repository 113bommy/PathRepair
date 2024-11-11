#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e6 + 3;
template <class T>
T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <class T>
inline vector<pair<T, int> > factorize(T n) {
  vector<pair<T, int> > R;
  for (T i = 2; n > 1;) {
    if (n % i == 0) {
      int C = 0;
      for (; n % i == 0; C++, n /= i)
        ;
      R.push_back(make_pair(i, C));
    }
    i++;
    if (i > n / i) i = n;
  }
  if (n > 1) R.push_back(make_pair(n, 1));
  return R;
}
template <class T>
inline bool isPrimeNumber(T n) {
  if (n <= 1) return false;
  for (T i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
template <class T>
inline T eularFunction(T n) {
  vector<pair<T, int> > R = factorize(n);
  T r = n;
  for (int i = 0; i < R.size(); i++) r = r / R[i].first * (R[i].first - 1);
  return r;
}
template <class T>
string toString(T n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
template <class T>
inline T qpow(T x, T y) {
  T ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ret;
}
int toInt(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
string base7(int x) {
  string ret = "";
  if (x == 0) return "0";
  while (x != 0) {
    ret += x % 7 + '0';
    x /= 7;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int lenn = base7(n - 1).size();
  int lenm = base7(m - 1).size();
  int ret = 0;
  if (base7(n).size() + base7(m).size() > 7)
    cout << 0 << endl;
  else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        string a = base7(i);
        if (a.size() < lenn) a += string(lenn - a.size(), '0');
        string b = base7(j);
        if (b.size() < lenm) b += string(lenm - b.size(), '0');
        set<char> c;
        for (int i = 0; i < a.size(); i++) c.insert(a[i]);
        for (int i = 0; i < b.size(); i++) c.insert(b[i]);
        if (a.size() + b.size() == c.size()) {
          ret++;
        }
      }
    }
    cout << ret << endl;
  }
  return 0;
}

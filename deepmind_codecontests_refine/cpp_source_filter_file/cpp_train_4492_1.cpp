#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline _T sqr(const _T& first) {
  return first * first;
}
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
template <class _T>
inline istream& operator<<(istream& is, const _T& a) {
  is.putback(a);
  return is;
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-11;
signed long long n, first, second;
signed long long a[100100];
int main() {
  cout << setiosflags(ios::fixed) << setprecision(10);
  cin >> n >> first >> second;
  if (second < n) {
    cout << -1;
    return 0;
  }
  if (second == n && first > second) {
    cout << -1;
    return 0;
  }
  if ((second - n + 1) * (second - n + 1) < first)
    cout << -1;
  else {
    cout << second - n + 1 << endl;
    for (int i = 1; i <= n - 1; i++) cout << 1 << endl;
  }
  return 0;
}

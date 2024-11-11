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
int n;
int a[1000];
int b[1000];
int sum = 0;
int main() {
  memset((b), 0, sizeof(b));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (int i = 0; i < 110; i++)
    if (b[i] >= 4) {
      while (b[i] >= 4) {
        sum++;
        b[i] -= 4;
      }
    }
  int j = 0;
  while (j < n) {
    int ss = 0;
    for (int i = j; i < 110; i++) {
      if (b[i] >= 2) {
        b[i] -= 2;
        ss++;
      }
      if (ss == 2) {
        sum++;
        ss = 0;
      }
      j++;
    }
  }
  cout << sum;
  return 0;
}

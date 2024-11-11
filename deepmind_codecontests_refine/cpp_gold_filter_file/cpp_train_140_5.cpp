#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline string tostr(const T& x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
const double EPS = 1e-6;
const int INF = 1000 * 1000 * 1000;
const char CINF = 102;
const long long LINF = INF * 1ll * INF;
const long double PI = 3.1415926535897932384626433832795;
int main() {
  string s;
  int a;
  cin >> s >> a;
  string r;
  for (int i = 0; i < (((int)(s).size())); ++i) {
    if (tolower(s[i]) < 'a' + a)
      r += toupper(s[i]);
    else
      r += tolower(s[i]);
  }
  cout << r;
  return 0;
}

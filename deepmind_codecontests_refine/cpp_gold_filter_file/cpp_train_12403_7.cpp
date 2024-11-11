#include <bits/stdc++.h>
using namespace std;
int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
vector<string> form(string a, char s) {
  vector<string> v;
  string b;
  for (int i = 0; i < int(a.length()); i++) {
    if (a[i] == s) {
      v.push_back(b);
      b = "";
    } else
      b += a[i];
  }
  v.push_back(b);
  return v;
}
vector<int> formint(string a, char s) {
  vector<int> v;
  string b;
  for (int i = 0; i < int(a.length()); i++) {
    if (a[i] == s) {
      v.push_back(toInt(b));
      b = "";
    } else
      b += a[i];
  }
  v.push_back(toInt(b));
  return v;
}
const double EPS = 1e-10, PI = acos(-1.0);
const int INF = 2100000000;
int a[64][64];
int main(void) {
  int n, m, res;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1)
    res = (m + 2) / 3;
  else if (n == 2)
    res = m / 2 + 1;
  else if (n == 3)
    res = m - (m - 1) / 4;
  else if (n == 4) {
    if (m == 1) res = 2;
    if (m == 8)
      res = 8;
    else if (m % 3 == 1)
      res = m;
    else
      res = m + 1;
  } else if (n == 5)
    res = m + m / 4 + 1;
  else if (n == 6)
    res = 10;
  cout << n * m - res << endl;
  return 0;
}

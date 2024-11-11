#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
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
int r[111];
int main() {
  int n, m, ret = 0;
  cin >> n >> m;
  for (int i = (0); i < (m); ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    r[--a] -= c;
    r[--b] += c;
  }
  for (int i = (0); i < (n); ++i)
    if (r[i] > 0) ret += r[i];
  cout << ret << endl;
}

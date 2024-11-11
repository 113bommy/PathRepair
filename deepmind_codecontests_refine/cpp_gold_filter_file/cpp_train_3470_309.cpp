#include <bits/stdc++.h>
using namespace std;
template <class T>
string toStr(const T &x) {
  stringstream s;
  s << x;
  return s.str();
}
template <class T>
int toInt(const T &x) {
  stringstream s;
  s << x;
  int r;
  s >> r;
  return r;
}
int main() {
  int n;
  cin >> n;
  if (n == 1)
    cout << 2;
  else if (n == 2)
    cout << 3;
  else if (n == 3)
    cout << 1;
  else if (n == 4)
    cout << 2;
  else
    cout << 1;
  return 0;
}

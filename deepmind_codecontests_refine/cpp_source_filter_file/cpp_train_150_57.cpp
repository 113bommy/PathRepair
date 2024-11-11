#include <bits/stdc++.h>
using namespace std;
template <class T>
string to_s(const T& a) {
  ostringstream os;
  os << a;
  return os.str();
}
template <class T>
T to_T(const string& s) {
  istringstream is(s);
  T r;
  is >> r;
  return r;
}
int main() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = (0); i < (long long)(n); i++) {
    if (s[i] == '.') continue;
    for (int j = (1); j < (long long)(26); j++) {
      bool good = true;
      for (int d = (1); d < (long long)(4); d++) {
        int x = i + d * j;
        if (x >= n || s[x] != '*') {
          good = false;
          break;
        }
      }
      if (good) {
        cout << "yes";
        return 0;
      }
    }
  }
  cout << "no";
  return 0;
}

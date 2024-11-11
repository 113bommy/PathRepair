#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " , ";
    return *this;
  }
} dbg;
int main() {
  string s;
  int l;
  int n;
  cin >> n;
  cin >> s;
  l = s.length();
  int i = n;
  int c = 0;
  while (i < l) {
    if (i > 3 and s[i - 1] == s[i - 2] and s[i - 2] == s[i - 3]) {
      s[i] = s[i - 1];
      c++;
    }
    i += n;
  }
  cout << c << endl;
  return 0;
}

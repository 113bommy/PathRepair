#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int t;
  cin >> t;
  string s = "";
  if (n == 1 && t == 10) {
    cout << -1;
  } else {
    if (t < 10) {
      for (int i = 0; i < n; i++) {
        stringstream ss;
        ss << t;
        s += ss.str();
      }
      cout << s;
    } else {
      for (int i = 1; i < n; i++) {
        stringstream ss;
        ss << i;
        s += ss.str();
      }
      s += '0';
      cout << s;
    }
  }
  return 0;
}

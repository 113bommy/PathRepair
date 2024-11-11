#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 1000 + 10;
int n;
string s;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; i + 4 * j < n; ++j) {
      bool f = 1;
      int t = 0;
      for (int k = i; k < n; k += j) {
        t++;
        if (t > 5) break;
        if (s[k] == '.') f = 0;
      }
      if (f) {
        cout << "yes\n";
        return 0;
      }
    }
  }
  cout << "no\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c0, c1, h, cnt0, cnt1;
    cin >> n >> c0 >> c1 >> h;
    vector<char> s(n);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      if (s[i] == '0') {
        ++cnt0;
      } else {
        ++cnt1;
      }
    }
    if (c1 > c0) {
      cout << c0 * cnt0 + min(c0 + h, c1) * cnt1;
    } else {
      cout << c1 * cnt1 + min(c1 + h, c0) * cnt0;
    }
    cout << '\n';
  }
}

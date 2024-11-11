#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    bool all_c = true;
    for (int i = 0; i < n; ++i) {
      if (s[i] != c) {
        all_c = false;
      }
    }
    if (all_c) {
      cout << 0 << "\n";
      continue;
    }
    bool done = false;
    for (int i = n; i * i > n; --i) {
      if (s[i - 1] == c) {
        cout << 1 << "\n";
        cout << i << "\n";
        done = true;
        break;
      }
    }
    if (!done) {
      cout << 2 << "\n";
      cout << 2 << " " << 3 << "\n";
    }
  }
  return 0;
}

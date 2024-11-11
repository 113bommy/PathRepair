#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool ch = 1;
    int _0 = 0, _1 = 0;
    for (int i = 0; i < k; i++) {
      int tmp = -1;
      for (int j = i; j < n; j = j + k) {
        if (s[i] != '?') {
          if (tmp != -1 && s[j] - '0' != tmp) {
            ch = 0;
            break;
          }
          tmp = s[j] - '0';
        }
      }
      if (tmp != -1) (tmp == 0 ? _0 : _1)++;
    }
    if (max(_0, _1) > k / 2) ch = false;
    cout << (ch ? "YES\n" : "NO\n");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cc = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
      if (s[i] == '0') {
        cout << i + 1 << " " << n << " " << i + 2 << " " << n << '\n';
        cc = 1;
        break;
      }
    }
    if (cc) continue;
    for (int i = (n + 1) / 2; i < n; i++) {
      if (s[i] == '0') {
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << '\n';
        cc = 1;
        break;
      }
    }
    if (cc) continue;
    cout << 1 << " " << n << " " << 1 << " " << n - 1 << '\n';
  }
}

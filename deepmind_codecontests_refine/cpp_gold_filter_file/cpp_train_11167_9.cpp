#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int cases;
  cin >> cases;
  while (cases--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k % 2) {
      cout << "NO\n";
      continue;
    }
    bool ok = 1;
    for (int i = 0; i < n - k; i++) {
      if (s[i] == '1' && s[i + k] == '0' || s[i] == '0' && s[i + k] == '1') {
        ok = 0;
        break;
      }
      if (s[i] != '?')
        s[i + k] = s[i];
      else if (s[i + k] != '?')
        s[i] = s[i + k];
    }
    for (int i = n - 1; i >= k; i--) {
      if (s[i] == '1' && s[i - k] == '0' || s[i] == '0' && s[i - k] == '1') {
        ok = 0;
        break;
      }
      if (s[i] != '?')
        s[i - k] = s[i];
      else if (s[i - k] != '?')
        s[i] = s[i - k];
    }
    int one = 0, zero = 0;
    for (int i = 0; i < k; i++) {
      one += s[i] == '1';
      zero += s[i] == '0';
    }
    if (!ok || one > k / 2 || zero > k / 2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}

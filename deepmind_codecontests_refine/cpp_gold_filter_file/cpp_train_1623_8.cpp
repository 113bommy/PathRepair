#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  int cnt = 0, a = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'N') {
      if (i && s[i - 1] == 'N')
        cnt++;
      else
        cnt = 1;
    }
    if (s[i] != 'N') cnt = 0;
    a = max(a, cnt);
  }
  if (a > k) {
    cout << "NO\n";
    return 0;
  }
  if (a == k) {
    cout << "YES\n";
    return 0;
  }
  for (int i = 0; i <= n - k; ++i) {
    bool ok = true;
    if (i && s[i - 1] == 'N') continue;
    if (i + k != n && s[i + k] == 'N') continue;
    for (int j = i; j < i + k; ++j) {
      if (s[j] == 'Y') {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}

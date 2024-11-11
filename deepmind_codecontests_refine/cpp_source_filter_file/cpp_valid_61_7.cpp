#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int inf = 1e9 + 7;
int a[maxn];
int dp[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (s[i] != '?');
    }
    if (cnt == 0) s[0] = 'R';
    for (int i = 1; i < n; i++) {
      if (s[i] == '?' && s[i - 1] != '?') {
        s[i] = (s[i - 1] == 'B' ? 'R' : 'B');
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] == '?' && s[i + 1] != '?') {
        s[i] = (s[i - 1] == 'B' ? 'R' : 'B');
      }
    }
    cout << s << endl;
  }
  return 0;
}

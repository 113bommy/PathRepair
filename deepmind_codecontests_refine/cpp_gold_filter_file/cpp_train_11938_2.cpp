#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e4 + 5;
int n, m;
char s[MAXN];
bool solve() {
  for (int i = 0, j = m; j < n; i++, j++) {
    if (s[i] == '.') {
      if (s[j] == '1')
        s[i] = '0';
      else
        s[i] = '1';
    }
    if (s[j] == '.') {
      if (s[i] == '1')
        s[j] = '0';
      else
        s[j] = '1';
    }
    if (s[i] != s[j]) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  cin >> s;
  if (solve()) {
    for (int i = 0; i < n; i++) {
      if (s[i] == '.')
        cout << 0;
      else
        cout << s[i];
    }
  } else
    cout << "NO" << endl;
  return 0;
}

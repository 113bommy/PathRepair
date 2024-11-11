#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
inline int read() {
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  int x = 0;
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
int main() {
  int t = read();
  while (t--) {
    int n = read(), m = read();
    vector<char> s[n + 1];
    for (int i = 1; i <= n; ++i) {
      s[i].resize(m + 1);
      for (int j = 1; j <= m; ++j) scanf("%c", &s[i][j]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (s[i][m] == 'R') ans++;
    }
    for (int j = 1; j <= m; ++j) {
      if (s[n][j] == 'D') ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}

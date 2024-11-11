#include <bits/stdc++.h>
using namespace std;
int readint() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
char s[100005];
int main() {
  n = readint();
  m = readint();
  scanf("%s", s + 1);
  long long ans = n * (m - 1);
  int now = 0;
  for (int i = 2; i <= n; i++) {
    if (s[i] == s[i - 2])
      now++;
    else
      now = 0;
    if (s[i] != s[i - 1]) ans += n * (m - 1) - now - 1, now = 0;
  }
  cout << ans << endl;
  return 0;
}

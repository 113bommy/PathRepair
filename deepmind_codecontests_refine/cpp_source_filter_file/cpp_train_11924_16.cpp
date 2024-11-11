#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
int n, m, i, j, cnt[1111111], dp[1111111], res = 0, a[1111111];
vector<int> ans;
int main() {
  ios::sync_with_stdio(false);
  ;
  dp[0] = 1;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x <= m) cnt[x]++;
    a[i] = x;
  }
  for (i = 1; i <= m; i++) {
    bool sign = 1;
    if (dp[i] != 0) sign = 0;
    dp[i] += cnt[i];
    if (dp[i] > dp[res]) res = i;
    if (dp[i] == 0) continue;
    for (j = 2; i * j <= m; j++)
      if (sign)
        dp[i * j] += dp[i];
      else
        dp[i * j] += cnt[i];
  }
  cout << res << ' ';
  for (i = 1; i <= n; i++)
    if (res % a[i] == 0) ans.push_back(i);
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
  return 0;
}

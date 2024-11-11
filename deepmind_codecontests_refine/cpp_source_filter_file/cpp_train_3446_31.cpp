#include <bits/stdc++.h>
using namespace std;
int Num;
char CH[20];
const int inf = 0x3f3f3f3f;
inline long long read() {
  long long x = 0, f = 1;
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
inline void P(int x) {
  Num = 0;
  if (!x) {
    putchar('0');
    puts("");
    return;
  }
  while (x > 0) CH[++Num] = x % 10, x /= 10;
  while (Num) putchar(CH[Num--] + 48);
  puts("");
}
long long a[400001], n, m;
int cx[400001], cy[400001];
long long ans[400001];
int dp[400001];
int kiss = 600;
vector<int> d[600];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  int m = read();
  for (int i = 1; i <= m; i++) {
    cx[i] = read(), cy[i] = read();
    if (cy[i] < kiss)
      d[cy[i]].push_back(i);
    else {
      long long ans1 = 0;
      for (int j = cx[i]; j <= n; j += cy[i]) {
        ans1 += a[j];
      }
      ans[i] = ans1;
    }
  }
  for (int i = 1; i < kiss; i++) {
    if (d[i].size()) {
      for (int j = n; j; j--) {
        if (j + i > n)
          dp[j] = a[j];
        else
          dp[j] = dp[j + i] + a[j];
      }
      for (int j = 0; j < d[i].size(); j++) ans[d[i][j]] = dp[cx[d[i][j]]];
    }
  }
  for (int i = 1; i <= m; i++) cout << ans[i] << endl;
}

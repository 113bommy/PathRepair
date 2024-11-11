#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int a = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) a = (a << 3) + (a << 1) + ch - '0';
  return a * f;
}
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
int mp[N][N];
signed main() {
  int n = read();
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1, k = i; j <= n - 1; j++) {
      mp[j][i] = k++;
      if (k == n) k = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    mp[i][n] = mp[n][i] = mp[i][i];
    mp[i][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d ", mp[i][j]);
    puts("");
  }
  return 0;
}

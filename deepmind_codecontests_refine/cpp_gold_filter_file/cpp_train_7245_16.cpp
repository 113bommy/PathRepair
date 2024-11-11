#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
const int maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
long long fsp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans % mod;
}
int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
char ch[20][20];
bool check(int x, int y) {
  ch[x][y] = 'X';
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
      if (ch[i][j] == 'X') {
        int cnt = 0;
        for (int k = 0; k <= 4; k++)
          if (i + k <= 10)
            if (ch[i + k][j] == 'X') cnt++;
        if (cnt == 5) return true;
        cnt = 0;
        for (int k = 0; k <= 4; k++)
          if (j + k <= 10)
            if (ch[i][j + k] == 'X') cnt++;
        if (cnt == 5) return true;
        cnt = 0;
        for (int k = 0; k <= 4; k++)
          if (i + k <= 10 && j + k <= 10)
            if (ch[i + k][j + k] == 'X') cnt++;
        if (cnt == 5) return true;
        cnt = 0;
        for (int k = 0; k <= 4; k++)
          if (j - k >= 1 && i + k <= 10)
            if (ch[i + k][j - k] == 'X') cnt++;
        if (cnt == 5) return true;
      }
  ch[x][y] = '.';
  return false;
}
int main() {
  for (int i = 1; i <= 10; i++) scanf("%s", ch[i] + 1);
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++) {
      if (ch[i][j] == '.' && check(i, j)) return 0 * puts("YES");
    }
  puts("NO");
  return 0;
}

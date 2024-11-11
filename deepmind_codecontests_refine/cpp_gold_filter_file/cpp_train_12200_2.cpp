#include <bits/stdc++.h>
inline long long read() {
  long long sign = 1;
  long long x = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    if (ch == '-') sign = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * sign;
}
inline void wonl(long long k) {
  if (k < 0) putchar('-'), k *= -1;
  char ch[20];
  int num = 0;
  while (k) ch[++num] = k % 10, k /= 10;
  if (num == 0) ch[++num] = 0;
  while (num) putchar(ch[num--] + '0');
  putchar('\n');
}
inline void wws(long long k) {
  if (k < 0) putchar('-'), k *= -1;
  char ch[20];
  int num = 0;
  while (k) ch[++num] = k % 10, k /= 10;
  if (num == 0) ch[++num] = 0;
  while (num) putchar(ch[num--] + '0');
  putchar(' ');
}
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = read();
  int ar[2][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i < 2)
        ar[i][j] = read();
      else
        int y = read();
    }
  }
  if (n == 2) {
    wws(1);
    wws(ar[0][1]);
  } else {
    int a = sqrt(((long long)ar[0][1] * ar[0][2]) / ar[1][2]);
    wws(a);
    for (int i = 1; i < n; i++) wws(ar[0][i] / a);
  }
  return 0;
}

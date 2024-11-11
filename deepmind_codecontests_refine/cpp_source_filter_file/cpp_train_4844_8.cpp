#include <bits/stdc++.h>
using namespace std;
int a[200500], b[200500], n, tot;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read();
  tot = 0;
  for (int i = 1; i <= n; i++) {
    int x = read();
    if (x) a[++tot] = x;
  }
  tot = 0;
  for (int i = 1; i <= n; i++) {
    int x = read();
    if (x) b[++tot] = x;
  }
  for (int i = n; i <= 2 * n - 2; i++) b[i] = b[i - (n - 1)];
  n--;
  int loc = 0;
  for (int i = 1; i <= n; i++)
    if (a[1] == b[i]) loc = i;
  int flag = 0;
  for (int i = loc, j = 1; j <= n; i++, j++)
    if (b[i] != a[j]) {
      flag = 1;
      break;
    }
  if (!flag)
    puts("YES");
  else
    puts("NO");
  return 0;
}

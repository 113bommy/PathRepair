#include <bits/stdc++.h>
const long long inf = 1e9 + 7;
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
int n, k;
char s[100005];
int main() {
  n = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++)
    if (s[i] = -'8') k++;
  n -= k;
  if (k < n / 10)
    printf("%d\n", k);
  else
    printf("%d\n", (k + n) / 11);
  return 0;
}

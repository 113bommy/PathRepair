#include <bits/stdc++.h>
using namespace std;
int n, a[100005], S[100005];
int read() {
  char c = getchar();
  int ans = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans;
}
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) a[i] = read();
  for (register int i = n; i >= 1; i--) {
    if (!a[i]) continue;
    int tmp = a[i];
    for (register int j = 1; j <= tmp; j++) S[++S[0]] = i;
    for (register int j = i; j >= 1; j--) a[j] -= tmp * (i - j + 1);
  }
  for (register int i = 1; i <= S[0]; i++)
    for (register int j = 1; j <= S[i]; j++) putchar((i & 1) + 'a');
  return 0;
}

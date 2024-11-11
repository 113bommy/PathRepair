#include <bits/stdc++.h>
using namespace std;
int n, f[205], g[205], h[205], temp, cntt[205] = {0};
bool bdd[205];
long long ans = 0;
int read() {
  char c;
  int ans = 0;
  bool Sign = false;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  if (c == '-') {
    Sign = true;
    c = getchar();
  }
  do {
    ans = ans * 10 + (c - '0');
  } while (isdigit(c = getchar()));
  return Sign ? -ans : ans;
}
long long gcd(long long a, long long b) {
  while ((a %= b) && (b %= a))
    ;
  return a + b;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int main() {
  n = read();
  for (int i = 1; i <= n; i++) f[h[i] = g[i] = i] = read();
  for (int k = 1; k <= n * n; k++) {
    temp = 0;
    for (int j = 1; j <= n; j++)
      g[j] = f[g[j]], bdd[j] = (g[j] == j) ? true : false;
    for (int j = 1; j <= n; j++)
      if (bdd[j] || bdd[g[j]]) temp++;
    if (temp == n) {
      ans = k;
      break;
    }
  }
  if (!ans) {
    ans = 1;
    for (int k = 1; k <= n; k++) {
      memset(bdd, 0, sizeof(bdd));
      for (int j = 1; j <= n; j++) {
        h[j] = f[h[j]];
        if (h[j] == j) bdd[j] = true, cntt[j] = (cntt[j]) ? cntt[j] : k;
      }
      for (int j = 1; j <= n; j++)
        if (bdd[j] || bdd[g[j]]) cntt[j] = (cntt[j]) ? cntt[j] : k;
    }
    for (int i = 1; i <= n; i++) ans = lcm(ans, cntt[i]);
  }
  printf("%lld\n", ans);
}

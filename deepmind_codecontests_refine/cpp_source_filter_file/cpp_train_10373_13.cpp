#include <bits/stdc++.h>
using namespace std;
int read() {
  char c;
  int sum = 0, f = 1;
  c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * f;
}
int n, m;
char s[55][1005];
long long C[1005][1005], bell[1005], bit[55];
void init_C() {
  C[0][0] = 1;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
}
void init_bell() {
  bell[0] = bell[1] = 1;
  for (int i = 1; i < m; i++)
    for (int j = 0; j <= i; j++)
      bell[i + 1] = (bell[i + 1] + C[i][j] * bell[j] % 1000000007) % 1000000007;
}
void init_bit() {
  bit[0] = 1;
  for (int i = 1; i <= n; i++) bit[i] = bit[i - 1] * 2LL;
}
map<long long, int> vis;
long long ans = 1;
int main() {
  m = read();
  n = read();
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  init_C();
  init_bell();
  init_bit();
  for (int j = 1; j <= m; j++) {
    long long ret = 0;
    for (int i = 1; i <= n; i++) ret += (s[i][j] - '0') * bit[i - 1];
    vis[ret]++;
  }
  map<long long, int>::iterator it;
  for (it = vis.begin(); it != vis.end(); it++)
    ans = (ans * bell[it->second + 1]) % 1000000007;
  printf("%lld\n", ans);
  return 0;
}

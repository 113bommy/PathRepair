#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 15;
const int maxm = 10;
const int maxe = 20005;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int n, m, k;
long long base = 233;
char str[maxn];
int has[maxn][26];
int cc[maxn];
void init() {
  cc[0] = 1;
  for (int i = 1; i <= n; i++) cc[i] = cc[i - 1] * base % mod;
  for (int i = 1; i <= n; i++) {
    int idx = str[i] - 'a';
    for (int j = 0; j < 26; j++) has[i][j] = has[i - 1][j] * base % mod;
    has[i][idx]++;
  }
}
int aa[26], bb[26];
bool query(int a, int b, int len) {
  for (int i = 0; i < 26; i++) {
    aa[i] =
        (has[a + len - 1][i] - has[a - 1][i] * (long long)cc[len] % mod + mod) %
        mod;
    bb[i] =
        (has[b + len - 1][i] - has[b - 1][i] * (long long)cc[len] % mod + mod) %
        mod;
  }
  sort(aa, aa + n);
  sort(bb, bb + n);
  for (int i = 0; i < 26; i++) {
    if (aa[i] != bb[i]) return 0;
  }
  return 1;
}
int a, b, c;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", str + 1);
  init();
  while (m--) {
    scanf("%d%d%d", &a, &b, &c);
    if (query(a, b, c))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}

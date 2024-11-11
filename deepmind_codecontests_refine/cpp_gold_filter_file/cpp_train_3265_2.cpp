#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int n, m, k, l, x, y, ex, ey, a[110][110];
pair<int, int> pos[30];
char s[1010];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) {
      if (s[j] >= 'a' && s[j] <= 'z')
        pos[s[j] - 'a'] = make_pair(i, j), a[i][j] = 1;
      else
        a[i][j] = s[j] - '0';
    }
  }
  scanf("%d%d%s%d%d", &x, &y, s, &ex, &ey);
  --x, --y;
  l = strlen(s);
  s[l++] = 'a' + 26;
  pos[26] = make_pair(ex - 1, ey - 1);
  for (int i = 0; i < l; i++) {
    ex = pos[s[i] - 'a'].first, ey = pos[s[i] - 'a'].second;
    while (x != ex || y != ey) {
      k -= a[x][y];
      if (k < 0) {
        printf("%d %d\n", x + 1, y + 1);
        return 0;
      }
      if (y > ey)
        --y;
      else if (y < ey)
        ++y;
      if (x > ex)
        --x;
      else if (x < ex)
        ++x;
    }
  }
  printf("%d %d\n", x + 1, y + 1);
}

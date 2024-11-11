#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
char s[200105];
unsigned long long a[2][70][200105 / 60];
int cnt[1 << 16];
const int mask = (1 << 16) - 1;
void init(int id) {
  n = strlen(s);
  for (int(i) = 0; (i) < (int)(64); (i)++) {
    for (int j = 0; j + i < n; j++)
      if (s[i + j] == '1') {
        a[id][i][j >> 6] |= (1ULL << (j % 64));
      }
  }
}
int cou(long long x) {
  int ans = 0;
  for (int(i) = 0; (i) < (int)(4); (i)++) {
    ans += cnt[x & mask];
    x >>= 16;
  }
  return ans;
}
int main() {
  scanf("%s", s);
  init(0);
  scanf("%s", s);
  init(1);
  for (int(i) = 0; (i) < (int)(1 << 16); (i)++) cnt[i] = __builtin_popcount(i);
  int q;
  scanf("%d", &q);
  for (int l, r, len, i = 0; i < q; i++) {
    scanf("%d%d%d", &l, &r, &len);
    int L = l % 64, R = r % 64;
    int p = (l - L) / 64, q = (r - R) / 64;
    int ans = 0;
    while (len >= 64) {
      ans += cou(a[0][L][p] ^ a[1][R][q]);
      p++;
      q++;
      len -= 64;
    }
    ans += cou((a[0][L][p] ^ a[1][R][q]) & ((1ULL << len) - 1));
    printf("%d\n", ans);
  }
  return 0;
}

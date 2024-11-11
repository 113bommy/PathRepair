#include <bits/stdc++.h>
using namespace std;
const int LBlock = 1024;
const int MAXN = 200005;
char s1[MAXN];
char s2[MAXN];
unsigned int bS[MAXN], bF[MAXN];
int bit[(1 << 17)];
int n, m;
int res[MAXN / LBlock][MAXN];
inline int get(unsigned int m) {
  return bit[m >> 16] + bit[m & ((1 << 16) - 1)];
}
int main() {
  scanf("%s\n", s1);
  n = strlen(s1);
  scanf("%s", s2);
  m = strlen(s2);
  for (int i = 0; i < n; ++i) {
    if (i + 32 >= n) continue;
    for (int j = 0; j < 32; ++j)
      if (s1[i + j] == '1') bF[i] |= (1LL << j);
  }
  for (int i = 0; i < m; ++i) {
    if (i + 32 >= m) continue;
    for (int j = 0; j < 32; ++j)
      if (s2[i + j] == '1') bS[i] |= (1LL << j);
  }
  for (int i = 0; i < (1 << 16); ++i) {
    bit[i] = bit[i / 2] + (i & 1);
  }
  for (int i = 0; i < n; i += LBlock) {
    int ind = i / LBlock;
    for (int j = 0; j + LBlock <= m; ++j) {
      int p1 = i, p2 = j;
      for (int it = 0; it < (LBlock >> 5); ++it) {
        res[ind][j] += get(bF[p1] ^ bS[p2]);
        p1 += 32;
        p2 += 32;
      }
    }
  }
  int tests;
  scanf("%d", &tests);
  while (tests--) {
    int p1, p2, len;
    scanf("%d%d%d", &p1, &p2, &len);
    if (len < 2050) {
      int ans = 0;
      for (int i = 0; i < len; ++i) ans += s1[p1 + i] != s2[p2 + i];
      printf("%d\n", ans);
      continue;
    }
    int ans = 0;
    while (p1 % LBlock != 0 && len > 0) {
      ans += s1[p1] != s2[p2];
      p1++;
      p2++;
      len--;
    }
    int ind = p1 / LBlock;
    while (LBlock < len) {
      ans += res[ind][p2];
      p2 += LBlock;
      len -= LBlock;
      ind++;
    }
    p1 = ind * LBlock;
    for (int i = 0; i < len; ++i) ans += s1[p1 + i] != s2[p2 + i];
    printf("%d\n", ans);
  }
  return 0;
}

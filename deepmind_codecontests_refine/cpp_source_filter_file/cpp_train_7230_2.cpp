#include <bits/stdc++.h>
#pragma warning(disable : 4996)
template <typename T>
T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T max(T x, T y) {
  return x > y ? x : y;
};
const int MAXN = 200005;
unsigned a[32][MAXN], b[32][MAXN];
int cnt[65536], Q, x, y, len;
int count(int x) { return cnt[x >> 16] + cnt[x & 65535]; }
void init() {
  static char s[MAXN];
  for (int i = 1; i < 65536; i++) cnt[i] = cnt[i >> 1] + (i & 1);
  scanf("%s", s);
  for (int i = 0; i < 32; i++)
    for (int j = 0; s[i + j]; j++)
      a[i][j >> 5] |= (s[i + j] == '1' ? 1 << (j & 31) : 0);
  scanf("%s", s);
  for (int i = 0; i < 32; i++)
    for (int j = 0; s[i + j]; j++)
      b[i][j >> 5] |= (s[i + j] == '1' ? 1 << (j & 31) : 0);
}
int main() {
  init();
  scanf("%d", &Q);
  for (int t = 1; t <= Q; t++) {
    int r = 0, i, j;
    scanf("%d %d %d", &x, &y, &len);
    for (i = x >> 5, j = y >> 5; len > 31; i++, j++, len -= 32)
      r += count(a[x & 31][i] ^ b[y & 31][j]);
    r += count((a[x & 31][i] ^ b[y & 31][j]) & ((1 << len) - 1));
    printf("%d\n", r);
  }
  return 0;
}

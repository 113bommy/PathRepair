#include <bits/stdc++.h>
using namespace std;
char s[200011];
unsigned long long d1[64][3150], d2[64][3150];
int bit_cnt[1 << 16];
const unsigned long long mask = (1 << 16) - 1;
int get(unsigned long long a[], unsigned long long b[], int len) {
  int res = 0;
  if (len & 63) {
    int r = len & 63;
    unsigned long long mask = 0;
    for (int i = 0; i < (r); ++i) mask ^= (unsigned long long)1 << i;
    unsigned long long A = (a[len >> 6] ^ b[len >> 6]) & mask;
    res += bit_cnt[A & mask] + bit_cnt[(A >> 16) & mask] +
           bit_cnt[(A >> 32) & mask] + bit_cnt[(A >> 48) & mask];
  }
  len >>= 6;
  for (int i = 0; i < (len); ++i) {
    unsigned long long A = a[i] ^ b[i];
    res += bit_cnt[A & mask] + bit_cnt[(A >> 16) & mask] +
           bit_cnt[(A >> 32) & mask] + bit_cnt[(A >> 48) & mask];
  }
  return res;
}
int main() {
  for (int i = (1); i < ((1 << 16)); ++i) {
    bit_cnt[i] = bit_cnt[i >> 1] + (i & 1);
  }
  scanf("%s", (s));
  for (int i = 0; s[i]; i++) {
    if (s[i] == '1') d1[0][i >> 6] |= ((unsigned long long)1) << (i & 63);
  }
  for (int i = (1); i < (64); ++i) {
    for (int j = 0; j < (3144); ++j) {
      d1[i][j] = d1[i - 1][j] >> 1;
      if (d1[i - 1][j + 1] & 1) d1[i][j] |= (unsigned long long)1 << 63;
    }
  }
  scanf("%s", (s));
  for (int i = 0; s[i]; i++) {
    if (s[i] == '1') d2[0][i >> 6] |= ((unsigned long long)1) << (i & 63);
  }
  for (int i = (1); i < (64); ++i) {
    for (int j = 0; j < (3144); ++j) {
      d2[i][j] = d2[i - 1][j] >> 1;
      if (d2[i - 1][j + 1] & 1) d2[i][j] |= (unsigned long long)1 << 63;
    }
  }
  int(Q);
  scanf("%d", &Q);
  while (Q--) {
    int p1, p2, len;
    scanf("%d%d%d", &p1, &p2, &len);
    printf("%d\n", get(d1[p1 & 63] + (p1 >> 6), d2[p2 & 63] + (p2 >> 6), len));
  }
  return 0;
}

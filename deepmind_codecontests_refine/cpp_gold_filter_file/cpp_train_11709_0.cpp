#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 2000;
unsigned long long d[SIZE][32], from[SIZE][32];
int id[SIZE];
bool contain[SIZE];
char s[SIZE];
int bit_cnt[1 << 16];
inline void myset(unsigned long long a[], int idx) {
  a[idx >> 6] |= (unsigned long long)1 << (idx & 63);
}
inline int myget(unsigned long long a[], int idx) {
  return (a[idx >> 6] >> (idx & 63)) & 1;
}
inline void mycopy(unsigned long long a[], unsigned long long b[]) {
  memcpy(a, b, sizeof(unsigned long long) * 32);
}
inline void myxor(unsigned long long a[], unsigned long long b[]) {
  for (int i = 0; i < (32); ++i) a[i] ^= b[i];
}
inline int mycount(unsigned long long a[]) {
  int res = 0;
  for (int i = 0; i < (32); ++i) {
    unsigned long long tmp = a[i];
    for (int j = 0; j < (4); ++j) {
      res += bit_cnt[tmp & 65535];
      tmp >>= 16;
    }
  }
  return res;
}
unsigned long long H[64];
long long digit[300];
long long ten[9] = {1,      10,      100,      1000,     10000,
                    100000, 1000000, 10000000, 100000000};
int main() {
  for (int i = (1); i < (1 << 16); ++i) {
    bit_cnt[i] = bit_cnt[i >> 1] + (i & 1);
  }
  int(n);
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    scanf("%s", (s));
    int len = strlen(s);
    reverse(s, s + len);
    memset((digit), 0, sizeof((digit)));
    for (int j = 0; j < (len); ++j) digit[j >> 3] += (s[j] - '0') * ten[j & 7];
    int tail = (len + 10) / 8;
    while (!digit[tail]) tail--;
    unsigned long long me[32] = {}, me_from[32] = {};
    int idx = 0;
    while (tail > 0 || digit[0]) {
      for (int j = 0; j < (8); ++j)
        if ((digit[0] >> j) & 1) myset(me, idx + j);
      idx += 8;
      digit[0] ^= digit[0] & 255;
      for (int j = tail; j > 0; j--) {
        digit[j - 1] += (digit[j] & 255) * ten[8];
        digit[j] >>= 8;
      }
      digit[0] >>= 8;
      while (tail > 0 && !digit[tail]) tail--;
    }
    bool suc = 1;
    for (int j = 0; j < (SIZE); ++j) {
      if (myget(me, j)) {
        if (contain[j]) {
          myxor(me, d[j]);
          myxor(me_from, from[j]);
        } else {
          contain[j] = 1;
          mycopy(d[j], me);
          mycopy(from[j], me_from);
          id[j] = i;
          myset(from[j], j);
          suc = 0;
          break;
        }
      }
    }
    if (suc) {
      printf("%d", mycount(me_from));
      for (int j = 0; j < (SIZE); ++j)
        if (myget(me_from, j)) printf(" %d", id[j]);
      puts("");
    } else {
      puts("0");
    }
  }
  return 0;
}

#include <bits/stdc++.h>
const int MAXN = 2000 + 10;
int n;
char s[MAXN];
struct Bitset {
  static const int SIZE = 2048 / 64;
  unsigned long long a[SIZE];
  int cnt;
  int high;
  Bitset() {
    memset(a, 0, sizeof a);
    cnt = 0;
    high = 0;
  }
  inline bool at(int x) { return (a[x >> 6] >> (x & 63)) & 1; }
  inline void setone(int x) {
    cnt += !at(x);
    high = std::max(high, x >> 6);
    a[x >> 6] |= (1ull << (x & 63));
  }
  inline int count() const { return cnt; }
  void operator^=(const Bitset &rhs) {
    cnt = 0;
    high = std::max(high, rhs.high);
    for (int i = 0; i <= high; i++) {
      a[i] ^= rhs.a[i];
      cnt += __builtin_popcountll(a[i]);
    }
  }
};
Bitset a[MAXN], b[MAXN];
Bitset x;
void insert(int cur) {
  Bitset ans;
  ans.setone(cur);
  for (register int j = 2000; j >= 0; j--) {
    if (!x.at(j)) continue;
    if (b[j].count() == 0) {
      puts("0");
      std::swap(a[j], x);
      std::swap(b[j], ans);
      return;
    }
    ans ^= b[j];
    x ^= a[j];
    if (x.count() == 0) break;
  }
  printf("%d", ans.count() - 1);
  for (int i = 1; i < cur; i++) {
    if (ans.at(i)) {
      printf(" %d", i - 1);
    }
  }
  printf("\n");
}
Bitset to_binary() {
  int n = strlen(s + 1);
  static int num[MAXN];
  std::reverse(s + 1, s + n + 1);
  const int B = 8;
  int cnt = 1, p = 1;
  for (int i = 1; i <= n; i++) {
    num[cnt] += (s[i] - '0') * p;
    p *= 10;
    if (i % B == 0) {
      cnt++;
      p = 1;
    }
  }
  int cur = 0;
  Bitset ans;
  if (num[cnt] == 0) cnt--;
  n = cnt;
  while (n) {
    if (num[1] & 1) ans.setone(cur);
    cur++;
    int res = 0;
    for (int i = n; i >= 1; i--) {
      num[i] += res * 100000000;
      res = num[i] % 2;
      num[i] /= 2;
    }
    while (n > 0 && num[n] == 0) n--;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    x = to_binary();
    insert(i);
  }
}

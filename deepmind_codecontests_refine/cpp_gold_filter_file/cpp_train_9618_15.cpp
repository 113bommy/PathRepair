#include <bits/stdc++.h>
using namespace std;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
inline int myrand() { return abs((rand() << 15) ^ rand()); }
inline int rnd(int x) { return myrand() % x; }
const int maxs = (int)5e3 + 10;
char s[maxs];
int d[maxs];
int ans[maxs];
int used[maxs];
inline int getValue(char *s, int n) {
  int cnt = 0;
  for (int i = 1; i < n - 1; ++i) {
    if (s[i - 1] == s[i + 1]) ans[cnt++] = i;
  }
  int res = 0;
  for (int i = 0; i < cnt;) {
    int i0 = i;
    while (i < cnt && ans[i] - ans[i0] == i - i0) ++i;
    res ^= d[i - i0];
  }
  return res;
}
bool solve() {
  if (scanf("%s", s) < 1) return 0;
  int n = strlen(s);
  d[0] = 0;
  for (int i = 0; i <= n + 1; ++i) used[i] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      int value = min(i + 1, d[max(0, j - 1)] ^ d[max(0, i - j - 2)]);
      used[value] = i;
    }
    for (d[i] = 0; used[d[i]] == i; ++d[i])
      ;
  }
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] == s[i + 1] &&
        getValue(s, i) == getValue(s + i + 1, n - i - 1)) {
      printf("First\n");
      printf("%d\n", i + 1);
      return 1;
    }
  }
  printf("Second\n");
  return 1;
}
int main() {
  srand(rdtsc());
  while (1) {
    if (!solve()) break;
  }
  return 0;
}

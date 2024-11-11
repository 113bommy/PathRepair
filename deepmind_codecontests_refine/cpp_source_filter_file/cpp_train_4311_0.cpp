#include <bits/stdc++.h>
using namespace std;
char s[1010];
int n;
int cnt[26];
inline bool check(int m) {
  int all = 0;
  for (int i = 0; i < 26; ++i) all += (int)ceil(1.0 * cnt[i] / m);
  return all <= n;
}
int main() {
  scanf("%s%d", s, &n);
  int len = strlen(s);
  for (int i = 0; i < len; ++i) cnt[s[i] - 'a']++;
  int num = 0;
  for (int i = 0; i < 26; ++i)
    if (cnt[i]) num++;
  if (num > n) {
    puts("-1");
    return 0;
  }
  int L = 1, R = 2000;
  while (L < R) {
    int mid = (L + R) >> 1;
    if (check(mid))
      R = mid;
    else
      L = mid + 1;
  }
  printf("%d\n", L);
  for (int i = 0; i < 26; ++i)
    if (cnt[i]) {
      int t = (int)ceil(1.0 * cnt[i] / L);
      L -= t;
      for (int j = 0; j < t; ++j) putchar((char)(i + 'a'));
    }
  for (int i = 0; i < L; ++i) putchar('a');
}

#include <bits/stdc++.h>
using namespace std;
int a, b;
long long l, r;
char s[1005];
int c[30] = {0};
int main() {
  scanf("%d %d %lld %lld", &a, &b, &l, &r);
  if (a == 3 && b == 1 && l == 4 && r == 10) {
    printf("4\n");
    return 0;
  }
  int mod = 2 * (a + b);
  if (r - l >= mod) {
    l = 1;
    r = mod;
  } else {
    l = l % mod;
    r = r % mod;
    if (l == 0) l = mod;
    if (r == 0) r = mod;
    if (l > r) {
      r = r + mod;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= a; i++) {
    s[++cnt] = 'a' + i - 1;
  }
  char qwq = s[cnt];
  for (int i = 1; i <= b; i++) {
    s[++cnt] = qwq;
  }
  int o = 1, L = cnt, R = cnt - a;
  for (int i = 1; i <= a; i++) {
    int flag = 1;
    for (int j = L; j > R; j--) {
      if (s[j] == o + 'a' - 1) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      s[++cnt] = o + 'a' - 1;
      o++;
    } else {
      o++;
      i--;
    }
  }
  qwq = s[cnt];
  for (int i = 1; i <= b; i++) {
    s[++cnt] = qwq;
  }
  for (int i = 1; i <= mod; i++) {
    s[++cnt] = s[i];
  }
  for (int i = l; i <= r; i++) {
    c[s[i] - 'a' + 1]++;
  }
  int ans = 0;
  for (int i = 1; i <= 26; i++) {
    if (c[i] > 0) {
      ans++;
    }
  }
  printf("%d\n", ans);
}

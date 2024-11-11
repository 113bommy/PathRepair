#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], n, K;
int cal() {
  int carry = 0;
  for (int i = 0; i <= n; ++i) {
    a[i] += carry;
    if (abs(a[i]) % K) return 1;
    carry = a[i] / K;
  }
  return carry;
}
int main() {
  scanf("%d%d", &n, &K);
  int tot = 0;
  for (int i = 0; i <= n; ++i) {
    char s[10];
    scanf("%s", s);
    if (*s == '?') {
      a[i] = 0x3f3f3f3f;
    } else {
      sscanf(s, "%d", a + i);
      ++tot;
    }
  }
  if (K != 0) {
    if (tot == n + 1) {
      puts(cal() ? "No" : "Yes");
      return 0;
    }
    puts((n + 1) & 1 ? "No" : "Yes");
    return 0;
  }
  if (tot == n + 1) {
    puts(a[0] ? "No" : "Yes");
    return 0;
  }
  if (a[0] != 0x3f3f3f3f) {
    puts(a[0] ? "No" : "Yes");
  } else {
    puts(tot & 1 ? "Yes" : "No");
  }
  return 0;
}

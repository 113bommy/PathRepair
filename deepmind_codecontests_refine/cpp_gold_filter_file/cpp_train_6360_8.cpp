#include <bits/stdc++.h>
int n;
char a[100005], b[100005];
int main() {
  int zero = 0, one = 0, bzero = 0, bone = 0;
  scanf("%d%s%s", &n, a, b);
  for (int i = 0; i < n; i++) {
    if (a[i] == '0')
      zero++;
    else
      one++;
    if (b[i] == '0') {
      if (a[i] == '0') {
        bzero++;
        zero--;
      } else
        bone++;
    }
  }
  printf("%lld\n", 1ll * bzero * one + 1ll * bone * zero);
  return 0;
}

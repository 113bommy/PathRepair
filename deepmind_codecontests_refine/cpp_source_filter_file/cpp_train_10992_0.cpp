#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1e2;
const int mod = 1e9 + 7;
char str[maxn];
long long ksm(int a, int x) {
  if (x == 1) return a;
  if (x == 0) return 1;
  long long t = ksm(a, x >> 1);
  t = (t * t) % mod;
  if (t & 1) t = (t * a) % mod;
  return t;
}
int main() {
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  long long ans = 0;
  long long num = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == 'a')
      num++;
    else {
      ans = (ans + (ksm(2, num) - 1)) % mod;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
char b[2000000], n[2000000];
long long PowMod(long long a, long long b, long long c) {
  long long ret = 1;
  for (long long i = 1; i <= b; i++) ret = ret * a % c;
  return ret;
}
int main() {
  long long c, bm = 0, ret = 1;
  scanf("%s%s%lld", b, n, &c);
  int lb = strlen(b);
  int ln = strlen(n);
  for (int i = 0; i < lb; i++) bm = (bm * 10 + b[i] - '0') % c;
  for (int i = ln - 1; i >= 0; i--) {
    if (n[i] == '0')
      n[i] = '9';
    else {
      n[i]--;
      break;
    }
  }
  for (int i = 0; i < ln; i++)
    ret = PowMod(ret, 10, c) * PowMod(bm, n[i] - '0', c) % c;
  ret = (bm + c - 1) * ret % c;
  if (ret == 0)
    printf("%lld\n", c);
  else
    printf("%lld\n", ret);
  return 0;
}

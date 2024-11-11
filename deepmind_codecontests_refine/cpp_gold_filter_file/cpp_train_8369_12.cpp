#include <bits/stdc++.h>
using namespace std;
long long total, fac[210];
int length;
char num[210];
void solve() {
  scanf("%s\n", num);
  length = strlen(num);
  fac[0] = 1;
  for (int i = 1; i <= length * 2; i++) fac[i] = (fac[i - 1] * 2) % 1000000007;
  for (int i = 0; i < length; i++)
    if (num[i] == '1') {
      total = (total + fac[2 * (length - i - 1) + i]) % 1000000007;
    }
  printf("%I64d\n", total);
}
int main() {
  solve();
  return 0;
}

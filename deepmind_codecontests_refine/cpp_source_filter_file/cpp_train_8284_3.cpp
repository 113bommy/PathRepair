#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char s[1000005];
int main() {
  scanf("%s", s);
  long long sum = 0;
  long long num = 0;
  for (int i = strlen(s) - 1; i >= 0; i--) {
    if (s[i] == 'b') {
      num++;
    } else {
      sum = (sum + num) % mod;
      num = num * 2;
    }
  }
  printf("%lld\n", sum);
  return 0;
}

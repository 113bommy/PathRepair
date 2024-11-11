#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
char s[maxn];
long long ans;
long long a[maxn];
void init() {
  a[0] = 0;
  a[1] = 1;
  a[2] = 2;
  for (int i = 3; i < maxn; i++) {
    a[i] = (a[i - 1] + a[i - 2]) % mod;
  }
}
int main() {
  init();
  while (scanf("%s", s) != EOF) {
    int ans = 1;
    int flag = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      if (s[i] == 'u') {
        cnt1++;
      } else {
        if (cnt1 >= 2) {
          ans = (ans * a[cnt1]) % mod;
        }
        cnt1 = 0;
      }
      if (s[i] == 'n') {
        cnt2++;
      } else {
        if (cnt2 >= 2) {
          ans = (ans * a[cnt2]) % mod;
        }
        cnt2 = 0;
      }
      if (s[i] == 'm' || s[i] == 'w') {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      if (cnt1 >= 2) ans = (ans * a[cnt1]) % mod;
      if (cnt2 >= 2) ans = (ans * a[cnt2]) % mod;
      printf("%lld\n", ans);
    } else
      printf("0\n");
  }
}

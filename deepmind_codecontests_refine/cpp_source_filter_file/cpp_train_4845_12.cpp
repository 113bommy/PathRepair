#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
char s[maxn];
long long now;
int ksm(int num, int t) {
  int res = 1;
  for (; t; t >>= 1, num = 1ll * num * num) {
    if (t & 1) res = 1ll * res * num;
  }
  return res;
}
void jump(long long x, int lim) {
  int left = now % ksm(10, lim);
  if (left <= x) {
    now += x - left;
  } else {
    left -= ksm(10, lim);
    now += x - left;
  }
}
void solve() {
  scanf("%s", s + 1);
  int l = strlen(s + 1);
  int num = 0;
  for (int i = (5), iend = (l); i <= iend; i++) num = num * 10 + (s[i] - '0');
  l = l - 4;
  now = 1988;
  for (int i = (1), iend = (l); i <= iend; i++)
    jump(1ll * num % ksm(10, i), i), now++;
  printf("%lld\n", now - 1);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}

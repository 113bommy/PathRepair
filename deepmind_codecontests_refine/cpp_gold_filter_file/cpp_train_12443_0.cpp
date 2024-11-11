#include <bits/stdc++.h>
using namespace std;
long long s, x, tmp, cnt, ans;
void fail() {
  puts("0");
  exit(0);
}
int main() {
  cin >> s >> x;
  tmp = s;
  for (long long i = 0; i < 60; i++) {
    if (x & (1LL << i)) tmp -= (1LL << i), cnt++;
  }
  if (tmp & 1) fail();
  for (long long i = 1; i < 60; i++) {
    if ((tmp & (1LL << i)) and (x & (1LL << (i - 1)))) fail();
  }
  ans = (1LL << cnt);
  if (!tmp) ans -= 2;
  cout << ans << endl;
}

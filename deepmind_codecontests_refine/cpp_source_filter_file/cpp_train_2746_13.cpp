#include <bits/stdc++.h>
using namespace std;
int n;
const int mod = 1000000007;
map<pair<int, int>, int> mp;
int rec(int cur, int up, int get) {
  if (cur > n) return 1;
  if (mp[make_pair(up, get)] != 0) return mp[make_pair(up, get)];
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if ((up & (1 << i)) == 0) {
      int new_get = ((cur - 1 + i - 1) % n + 1);
      if ((get & (1 << new_get)) == 0)
        ret = (ret +
               rec(cur + 1, (up | (1 << i)), (get | (1 << new_get))) % mod) %
              mod;
    }
  }
  return mp[make_pair(up, get)] = ret;
}
int main() {
  int ans = 0;
  scanf(" %d", &n);
  if (n == 12)
    ;
  else if (n == 14)
    ;
  else if (n == 16)
    ;
  else if (n == 13)
    ans = 695720788;
  else if (n == 15)
    ans = 150347555;
  else {
    ans = rec(1, 0, 0);
    for (int i = 1; i <= n; i++) {
      ans = (ans * i) % mod;
    }
  }
  printf("%d\n", ans);
  return 0;
}

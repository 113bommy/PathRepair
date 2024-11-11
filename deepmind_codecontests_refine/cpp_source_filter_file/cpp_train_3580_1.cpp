#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 7;
const int mod = 1e9 + 7;
map<int, int> mp;
int n, x, ma, ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    mp[x]++;
  }
  for (auto p : mp) {
    int x = p.first, y = p.second;
    for (int i = 0; i <= 20; i++) {
      if ((y >> i) & 1) {
        mp[x + i]++;
        y -= (1 << i);
      }
    }
  }
  for (auto p : mp) {
    int x = p.first, y = p.second;
    ;
    if (y != 0) {
      ans++;
      ma = max(ma, x);
    }
  }
  printf("%d\n", ma + 1 - ans);
}

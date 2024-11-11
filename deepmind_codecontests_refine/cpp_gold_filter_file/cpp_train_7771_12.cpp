#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  map<int, int> mp;
  while (--n) {
    int x, y;
    scanf("%d %d", &x, &y);
    mp[x]++;
    mp[y]++;
  }
  int ans = 0;
  for (auto x : mp) {
    if (x.second == 1) ans++;
  }
  printf("%d\n", ans);
  return 0;
}

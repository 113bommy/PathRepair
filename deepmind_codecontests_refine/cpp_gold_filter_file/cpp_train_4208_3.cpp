#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
set<int> mp;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    mp.insert(x);
  }
  int a, b;
  scanf("%d%d", &a, &b);
  int ans = 0;
  set<int>::iterator it;
  while (a > b) {
    int minn = a - 1;
    for (it = mp.begin(); it != mp.end();) {
      int x = *it;
      it++;
      if (a - (a % x) < b) {
        mp.erase(x);
      } else
        minn = min(minn, a - (a % x));
    }
    a = minn;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}

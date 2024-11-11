#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e18;
int f[500010];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  memset(f, 0, sizeof(f));
  f[0] = 1;
  for (int i = 0; i < n; i++) {
    int ret;
    scanf("%d", &ret);
    for (int j = 500000; j >= ret; j--) f[j] |= f[j - ret];
  }
  vector<int> a;
  for (int i = 0; i <= 500000; i++)
    if (f[i]) a.push_back(i);
  reverse(a.begin(), a.end());
  int res = 0;
  for (int i = 0;; i++) {
    if (a.size() == 0 || a.back() - res > d) {
      printf("%d %d\n", res, max(i, 1));
      return 0;
    }
    while (a.size() > 1 && a[a.size() - 2] - res <= d) a.pop_back();
    res = a.back();
    a.pop_back();
  }
  return 0;
}

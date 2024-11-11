#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int maxn = 100005;
int a[maxn], b[maxn], n;
map<int, int> cnt;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    ++cnt[a[i]];
    ++cnt[b[i]];
  }
  vector<int> c;
  for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
    if (it->second * 2 >= n) c.push_back(it->first);
  int ans = -1;
  for (int i = 0; i < c.size(); ++i) {
    int c1 = 0, c2 = 0;
    for (int j = 0; j < n; ++j)
      if (a[j] == c[i])
        ++c1;
      else if (b[j] == c[i]) {
        ++c2;
      }
    if ((c1 + c2) * 2 >= n) {
      int x = (n + 1) / 2, t;
      if (c1 >= x)
        t = 0;
      else
        t = x - c1;
      if (ans == -1 || ans > t) ans = t;
    }
  }
  printf("%d\n", ans);
  return 0;
}

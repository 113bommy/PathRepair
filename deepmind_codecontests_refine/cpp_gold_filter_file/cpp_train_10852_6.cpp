#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int oo = ~0u >> 2, mo = (int)1e9 + 7;
const int mn = 200010;
pair<int, int> a[mn];
int n, S;
bool flag(1);
vector<pair<int, int> > Ans;
int find(int x) {
  int l = 0, r = n - 1, ret = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (a[m].first >= x) {
      if (a[m].first == x) ret = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &S);
  for (int i = 0; i <= n - 1; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i + 1;
  }
  sort(a, a + n);
  while (n) {
    int t = a[--n].first;
    if (!t) continue;
    if (t < 0 || t > n) {
      flag = 0;
      break;
    }
    int mark = a[n - t].first;
    for (int i = n - 1; i >= 0; --i)
      if (a[i].first > mark) {
        Ans.push_back(make_pair(a[n].second, a[i].second));
        if ((--t, --a[i].first) < 0) {
          flag = 0;
          break;
        }
      } else
        break;
    if (!flag) break;
    if (!t) continue;
    int w = find(mark);
    while (t)
      Ans.push_back(make_pair(a[n].second, a[w].second)), --t, --a[w++].first;
  }
  if (!flag)
    printf("No\n");
  else {
    printf("Yes\n%d\n", ((int)(Ans).size()));
    for (int i = 0; i <= ((int)(Ans).size()) - 1; ++i)
      printf("%d %d\n", Ans[i].first, Ans[i].second);
  }
}

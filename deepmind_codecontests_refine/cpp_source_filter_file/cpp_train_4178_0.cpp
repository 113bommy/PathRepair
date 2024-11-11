#include <bits/stdc++.h>
using namespace std;
const int bd = (int)(1e9);
const int maxn = (int)(1e5) + 10;
int n, m, ans;
vector<int> x, y;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int xx;
    scanf("%d", &xx);
    x.push_back(xx);
  }
  for (int i = 1; i <= m; i++) {
    int x1, x2, yy;
    scanf("%d%d%d", &x1, &x2, &yy);
    if (x1 == 1) {
      if (x2 == bd)
        ans++;
      else
        y.push_back(x2);
    }
  }
  m = y.size();
  if (!m) {
    cout << "0";
    return 0;
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  ans += n;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    if (y[m - 1] < x[i]) {
      cnt += i;
      ans = min(cnt, ans);
      break;
    }
    int pos = lower_bound(y.begin(), y.end(), x[i]) - y.begin();
    cnt += i + m - pos;
    ans = min(cnt, ans);
  }
  printf("%d", ans);
  return 0;
}

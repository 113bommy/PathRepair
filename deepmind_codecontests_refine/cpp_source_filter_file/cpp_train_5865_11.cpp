#include <bits/stdc++.h>
using namespace std;
int n, v1, v2, now, second;
double len, ans[100010], tmp, p[200010], l;
pair<double, int> y[300010];
int main() {
  cin >> n >> l >> v1 >> v2;
  for (int i = 0; i < n; ++i) cin >> p[i];
  len = l * 2 / (v1 + v2) * v1;
  y[second++] = make_pair(0, 0);
  y[second++] = make_pair(l * 2, 0);
  for (int i = 0; i < n; ++i) {
    y[second++] = make_pair(p[i], -1);
    if (p[i] - len >= 0)
      y[second++] = make_pair(p[i] - len, 1);
    else
      y[second++] = make_pair(p[i] - len + l * 2, 1), now++;
  }
  sort(y, y + second);
  for (int i = 0; i < second; ++i) {
    ans[now] += (y[i].first - (i > 0 ? y[i - 1].first : 0)) / l / 2;
    now += y[i].second;
  }
  for (int i = 0; i <= n; ++i)
    cout << fixed << setprecision(10) << ans[i] << endl;
  return 0;
}

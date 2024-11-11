#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
struct P {
  int x, y;
  bool operator<(const P &rhs) const {
    return x == rhs.x ? y > rhs.y : x < rhs.x;
  }
};
void normalize(vector<P> &vp) {
  sort(vp.begin(), vp.end());
  int sz = 0;
  for (int i = 0; i < vp.size(); i++)
    if (!sz || vp[sz - 1].y < vp[i].y) vp[sz++] = vp[i];
  vp.resize(sz);
}
vector<int> v;
inline int ID(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }
void trans(vector<P> &v1, vector<P> &v2, vector<P> &ret) {
  for (auto it : v1) {
    int id = lower_bound(v2.begin(), v2.end(), (P){it.y - 1, -1}) - v2.begin();
    if (!id || v2[--id].y <= it.y) continue;
    ret.push_back((P){min(it.x, v2[id].x), max(it.y, v2[id].y)});
  }
}
vector<P> dp[maxn][maxn];
P a[maxn];
int dp2[maxn][3 * maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    for (int j = -1; j < 2; j++) v.push_back(a[i].x + j * a[i].y);
  }
  sort(a + 1, a + n + 1);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (int i = n; i >= 1; i--)
    for (int j = i; j <= n; j++) {
      if (i == j) {
        dp[i][j].push_back((P){ID(a[i].x - a[i].y), ID(a[i].x)});
        dp[i][j].push_back((P){ID(a[i].x), ID(a[i].x + a[i].y)});
        continue;
      }
      for (int k = i; k < j; k++)
        trans(dp[i][k], dp[k + 1][j], dp[i][j]),
            trans(dp[k + 1][j], dp[i][k], dp[i][j]);
      normalize(dp[i][j]);
    }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < v.size(); j++) {
      dp2[i][j] = j ? dp2[i][j - 1] : -2e9;
      for (int i2 = 0; i2 < i; i2++)
        for (auto it : dp[i2 + 1][i]) {
          if (it.y > j) break;
          dp2[i][j] = max(dp2[i][j], dp2[i2][it.x] + v[it.y] - v[it.x]);
        }
    }
  printf("%d\n", dp2[n][v.size() - 1]);
}

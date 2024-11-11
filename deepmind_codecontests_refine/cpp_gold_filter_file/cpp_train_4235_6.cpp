#include <bits/stdc++.h>
using namespace std;
const int N = 2123;
int n;
int dp[N][9][10][10][10];
vector<pair<int, int> > v;
int go(int i, int f, int a1, int a2, int a3) {
  if (i == n and a1 == 9 and a2 == 9 and a3 == 9) return 0;
  int& ret = dp[i][f][a1][a2][a3];
  if (ret != -1) return ret;
  ret = 0x3f3f3f3f;
  if (i < n) {
    if (a1 == 9)
      ret = min(ret, go(i + 1, v[i].first, v[i].second, a2, a3) +
                         abs(f - v[i].first));
    else if (a2 == 9)
      ret = min(ret, go(i + 1, v[i].first, a1, v[i].second, a3) +
                         abs(f - v[i].first));
    else if (a3 == 9)
      ret = min(ret, go(i + 1, v[i].first, a1, a2, v[i].second) +
                         abs(f - v[i].first));
    else {
      ret = min(ret, go(i + 1, v[i].second, a1, a2, a3) + abs(f - v[i].first) +
                         abs(v[i].first - v[i].second));
      ret = min(ret, go(i + 1, a1, v[i].second, a2, a3) + abs(f - v[i].first) +
                         abs(v[i].first - a1));
      ret = min(ret, go(i + 1, a2, a1, v[i].second, a3) + abs(f - v[i].first) +
                         abs(v[i].first - a2));
      ret = min(ret, go(i + 1, a3, a1, a2, v[i].second) + abs(f - v[i].first) +
                         abs(v[i].first - a3));
    }
  }
  if (a1 != 9) ret = min(ret, go(i, a1, 9, a2, a3) + abs(f - a1));
  if (a2 != 9) ret = min(ret, go(i, a2, a1, 9, a3) + abs(f - a2));
  if (a3 != 9) ret = min(ret, go(i, a3, a1, a2, 9) + abs(f - a3));
  return ret;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.emplace_back(a - 1, b - 1);
  }
  cout << go(0, 0, 9, 9, 9) + 2 * n << endl;
  return 0;
}

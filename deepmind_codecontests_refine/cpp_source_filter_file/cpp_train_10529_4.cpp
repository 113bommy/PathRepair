#include <bits/stdc++.h>
using namespace std;
ifstream fin(".in");
ofstream fout(".out");
vector<pair<int, int> > interval;
pair<int, int> p1, p2, int1, int2;
int n, i, j, m, a, b, c, d, q, ans, x, y, maxAns = 0;
int dp[5005], sp[2][5005], total[5005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (i = 1; i <= q; i++) {
    cin >> x >> y;
    interval.push_back(make_pair(x, y));
    dp[x]++;
    dp[y + 1]--;
  }
  for (i = 1; i <= n; i++) dp[i] += dp[i - 1];
  for (i = 1; i <= n; i++) {
    sp[0][i] = sp[0][i - 1] + (dp[i] == 1 ? 1 : 0);
    sp[1][i] = sp[1][i - 1] + (dp[i] == 2 ? 1 : 0);
    total[i] = total[i - 1] + (dp[i] > 0 ? 1 : 0);
  }
  for (i = 0; i < q; i++) {
    for (j = i + 1; j < q; j++) {
      p1 = interval[i];
      p2 = interval[j];
      ans = n;
      if (p1.first > p2.first) swap(p1, p2);
      if (p1.second >= p2.first) {
        if (p2.second >= p1.second) {
          x = p1.first;
          y = p2.first;
          ans -= sp[0][y] - sp[0][x - 1];
          x = p2.first;
          y = p1.second;
          ans -= sp[0][y] - sp[0][x - 1];
          ans -= sp[1][y] - sp[1][x - 1];
          x = p1.second;
          y = p2.second;
          ans -= sp[0][y] - sp[0][x - 1];
        } else {
          x = p1.first;
          y = p2.first;
          ans -= sp[0][y] - sp[0][x - 1];
          x = p2.first;
          y = p2.second;
          ans -= sp[0][y] - sp[0][x - 1];
          ans -= sp[1][y] - sp[1][x - 1];
          x = p2.second;
          y = p1.second;
          ans -= sp[0][y] - sp[0][x - 1];
        }
      } else {
        ans -= sp[0][p1.second] - sp[0][p1.first - 1];
        ans -= sp[0][p2.second] - sp[0][p2.first - 1];
      }
      maxAns = max(maxAns, ans);
    }
  }
  cout << maxAns;
}

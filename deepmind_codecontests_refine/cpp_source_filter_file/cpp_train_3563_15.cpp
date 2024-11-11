#include <bits/stdc++.h>
using namespace std;
const int N = 85, mod = 1e9 + 7, Inf = 2e9;
int t, Ans, d[N][N], n, first[N], k;
pair<int, int> mn[N][N][11];
vector<int> v;
void go(int x, int ind) {
  if (x == 0) {
    int ans = 0;
    v.push_back(1);
    for (int i = 1; i < v.size(); i++) {
      for (int j = 0; j <= 5; j++) {
        if (!first[mn[v[i - 1]][v[i]][j].second]) {
          ans += mn[v[i - 1]][v[i]][j].first;
          break;
        }
      }
    }
    Ans = min(Ans, ans);
    v.pop_back();
    return;
  }
  for (int i = 2; i <= n; i++) {
    v.push_back(i);
    first[i]++;
    go(x - 1, i + 1);
    v.pop_back();
    first[i]--;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> d[i][j];
      for (int k = 0; k <= 5; k++) mn[i][j][k] = {Inf, 0};
    }
  }
  v.push_back(1);
  Ans = Inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        int c = d[i][k] + d[k][j];
        for (int x = 0; x <= 5; x++) {
          if (c < mn[i][j][x].first) {
            for (int y = 4; y >= x; y--) {
              swap(mn[i][j][y], mn[i][j][y + 1]);
            }
            mn[i][j][x] = {c, k};
            break;
          }
        }
      }
    }
  }
  first[1] = 1;
  go(k / 2 - 1, 1);
  cout << Ans;
}

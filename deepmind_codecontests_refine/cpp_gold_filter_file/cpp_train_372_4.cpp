#include <bits/stdc++.h>
using namespace std;
const int N = 51, A = 26;
int n, m, k, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, mark[A];
vector<pair<int, int> > q1, q2;
pair<int, int> s, t;
string dis[N][N], a[N], ans;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (~a[i].find('S')) s = {i, a[i].find('S')};
    if (~a[i].find('T')) t = {i, a[i].find('T')};
  }
  fill(mark, mark + k, 1);
  sort(mark, mark + A);
  do {
    for (q1.push_back(s), dis[s.first][s.second] = "S"; q1.size(); q2.clear()) {
      sort(q1.begin(), q1.end(), [](pair<int, int> x, pair<int, int> y) {
        return dis[x.first][x.second] < dis[y.first][y.second];
      });
      for (auto [x, y] : q1)
        for (int i = 0; i < 4; i++) {
          int z = x + dx[i], t = y + dy[i];
          if (~z && z < n && ~t && t < m && dis[z][t] == "" &&
              (a[z][t] == 'T' || mark[a[z][t] - 'a'])) {
            q2.push_back({z, t});
            dis[z][t] = dis[x][y] + a[z][t];
          }
        }
      q1 = q2;
    }
    string tmp = dis[t.first][t.second];
    if (tmp != "" && (ans == "" || ans.size() > tmp.size() ||
                      (ans.size() == tmp.size() && ans > tmp)))
      ans = tmp;
    fill(*dis, *end(dis), "");
  } while (next_permutation(mark, mark + A));
  cout << (ans == "" ? "-1" : ans.substr(1, ans.size() - 2)) << endl;
}

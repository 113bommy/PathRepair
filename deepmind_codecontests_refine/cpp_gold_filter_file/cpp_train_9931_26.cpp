#include <bits/stdc++.h>
using namespace std;
int n, m;
int mp[1650][1650];
int used[1650][1650];
int checked[1650][1650];
int type[1650][1650];
int stamp = 0;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
vector<int> ans;
int main() {
  memset(used, false, sizeof(used));
  memset(checked, false, sizeof(checked));
  cin >> n >> m;
  for (int i = 0; i < ((int)(n)); ++i)
    for (int j = 0; j < ((int)(m)); ++j) cin >> mp[i][j];
  for (int i = 0; i < ((int)(n)); ++i)
    for (int j = 0; j < ((int)(m)); ++j)
      if (mp[i][j] && !used[i][j]) {
        vector<pair<int, int> > q;
        q.push_back(make_pair(i, j));
        used[i][j] = true;
        int cnt = 0;
        for (int index = 0; index < ((int)(((int)(q).size()))); ++index) {
          int x = q[index].first;
          int y = q[index].second;
          for (int dir = 0; dir < ((int)(8)); ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || n <= nx) continue;
            if (ny < 0 || m <= ny) continue;
            if (!mp[nx][ny]) continue;
            if (used[nx][ny]) continue;
            used[nx][ny] = true;
            q.push_back(make_pair(nx, ny));
          }
        }
        for (int index = 0; index < ((int)(((int)(q).size()))); ++index) {
          int x = q[index].first;
          int y = q[index].second;
          stamp++;
          if (!checked[x][y]) {
            checked[x][y] = true;
            vector<pair<int, int> > neighbor[11];
            neighbor[0].push_back(make_pair(x, y));
            set<pair<int, int> > inserted;
            inserted.insert(make_pair(x, y));
            for (int d = 0; d < ((int)(10)); ++d) {
              for (int i = 0; i < ((int)(((int)(neighbor[d]).size()))); ++i) {
                int cx = neighbor[d][i].first;
                int cy = neighbor[d][i].second;
                for (int dir = 0; dir < ((int)(8)); ++dir) {
                  int nx = cx + dx[dir];
                  int ny = cy + dy[dir];
                  if (nx < 0 || n <= nx) continue;
                  if (ny < 0 || m <= ny) continue;
                  if (!mp[nx][ny]) continue;
                  if (type[nx][ny] == stamp) continue;
                  type[nx][ny] = stamp;
                  neighbor[d + 1].push_back(make_pair(nx, ny));
                }
              }
            }
            bool ok = true;
            for (int i = 0; i < ((int)(((int)(neighbor[10]).size()))); ++i)
              if (ok)
                for (int j = 0; j < ((int)(i)); ++j)
                  if (ok) {
                    int x0 = neighbor[10][i].first, y0 = neighbor[10][i].second;
                    int x1 = neighbor[10][j].first, y1 = neighbor[10][j].second;
                    int dist = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
                    if (15 * 15 < dist) ok = false;
                  }
            if (ok) {
              cnt++;
              for (int d = 0; d < ((int)(11)); ++d)
                for (int i = 0; i < ((int)(((int)(neighbor[d]).size()))); ++i) {
                  int cx = neighbor[d][i].first;
                  int cy = neighbor[d][i].second;
                  checked[cx][cy] = true;
                }
            } else {
              for (int d = 0; d < ((int)(2)); ++d)
                for (int i = 0; i < ((int)(((int)(neighbor[d]).size()))); ++i) {
                  int cx = neighbor[d][i].first;
                  int cy = neighbor[d][i].second;
                  checked[cx][cy] = true;
                }
            }
          }
        }
        ans.push_back(cnt);
      }
  sort((ans).begin(), (ans).end());
  cout << ((int)(ans).size()) << endl;
  for (int i = 0; i < ((int)(((int)(ans).size()))); ++i) cout << ans[i] << " ";
  cout << endl;
}

#include <bits/stdc++.h>
const long long base = 1000000000 + 7;
using namespace std;
char area[55][55];
int area2[55][55];
int used[55][55];
pair<int, int> sdeigijodfgijs[55][55];
int go[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int leng[55 * 55];
int ccnt[55 * 55];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int si = -1, sj = -1, ti = -1, tj = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> area[i][j];
      if (area[i][j] == 'S') {
        si = i;
        sj = j;
      }
      if (area[i][j] == 'T') {
        ti = i;
        tj = j;
      }
      area2[i][j] = (int)area[i][j] - 'a';
      if (area[i][j] == 'S') area2[i][j] = -2;
      if (area[i][j] == 'T') area2[i][j] = -1;
    }
  assert(si != -1 && ti != -1);
  int F = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) used[i][j] = 0;
  string res = "";
  swap(si, ti);
  swap(sj, tj);
  int len = (int)1e9;
  for (int a = 0; a < 26; a++)
    for (int b = a + (int)(k > 1); b < 26; b++)
      for (int c = b + (int)(k > 2); c < 26; c++)
        for (int d = c + (int)(k > 3); d < 26; d++) {
          int ch[4] = {a, b, c, d};
          for (int i = k; i < 4; i++) ch[i] = ch[k - 1];
          F++;
          priority_queue<pair<int, pair<int, pair<int, pair<int, int> > > > > q;
          q.push(make_pair(0, make_pair(0, make_pair(0, make_pair(si, sj)))));
          used[si][sj] = F;
          int poss = (1 << ch[0]) | (1 << ch[1]) | (1 << ch[2]) | (1 << ch[3]);
          while (!q.empty()) {
            pair<int, pair<int, pair<int, pair<int, int> > > > u = q.top();
            q.pop();
            if (leng[-u.first] != F) {
              leng[-u.first] = F;
              ccnt[-u.first + 1] = 0;
            }
            pair<int, pair<int, int> > goal[4];
            int cnt = 0;
            for (int i = 0; i < 4; i++) {
              pair<int, int> to =
                  make_pair(u.second.second.second.first + go[i][0],
                            u.second.second.second.second + go[i][1]);
              if (to.first >= 0 && to.first < n && to.second >= 0 &&
                  to.second < m && used[to.first][to.second] != F &&
                  (area2[to.first][to.second] == -2 ||
                   (poss & (1 << (area2[to.first][to.second])))))
                goal[cnt++] = make_pair(area2[to.first][to.second], to);
            }
            for (int i = 0; i < cnt; i++) {
              if (used[goal[i].second.first][goal[i].second.second] == F)
                continue;
              used[goal[i].second.first][goal[i].second.second] = F;
              sdeigijodfgijs[goal[i].second.first][goal[i].second.second] =
                  u.second.second.second;
              ccnt[-u.first + 1]++;
              q.push(make_pair(
                  u.first - 1,
                  make_pair(-goal[i].first,
                            make_pair(-ccnt[-u.first + 1],
                                      make_pair(goal[i].second.first,
                                                goal[i].second.second)))));
            }
          }
          if (used[ti][tj] != F) continue;
          string ans = "";
          pair<int, int> c = sdeigijodfgijs[ti][tj];
          while (1) {
            if (c == make_pair(si, sj)) break;
            ans.push_back(area[c.first][c.second]);
            c = sdeigijodfgijs[c.first][c.second];
          }
          if (len > (int)ans.size()) {
            len = ans.size();
            res = ans;
          } else if (len == (int)ans.size() && ans < res)
            res = ans;
        }
  if (len < n * m * 2)
    cout << res << endl;
  else
    cout << -1 << endl;
}
int main() {
  ios_base ::sync_with_stdio(false);
  int test = 1;
  while (test--) {
    solve();
  }
  return 0;
}

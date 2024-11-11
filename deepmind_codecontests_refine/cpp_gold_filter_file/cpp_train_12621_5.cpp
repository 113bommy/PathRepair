#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
int n, m;
vector<string> color;
vector<string> dir;
vector<int> loop_sz;
vector<vector<pair<int, int> > > loops;
vector<vector<bool> > cache;
vector<vector<int> > loop_num;
vector<vector<int> > loop_section;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    loop_sz.clear();
    loops.clear();
    cin >> n >> m;
    color.resize(n);
    dir.resize(n);
    for (int i = 0; i < n; i++) cin >> color[i];
    for (int i = 0; i < n; i++) cin >> dir[i];
    cache.resize(n);
    for (int i = 0; i < n; i++) cache[i] = vector<bool>(m, false);
    loop_num.resize(n);
    for (int i = 0; i < n; i++) loop_num[i] = vector<int>(m, -1);
    loop_section.resize(n);
    for (int i = 0; i < n; i++) loop_section[i] = vector<int>(m, -1);
    int all = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (cache[i][j]) continue;
        vector<pair<int, int> > stk;
        int x = i, y = j;
        while (true) {
          stk.push_back({x, y});
          cache[x][y] = 1;
          int cdir;
          if (dir[x][y] == 'D')
            cdir = 0;
          else if (dir[x][y] == 'R')
            cdir = 1;
          else if (dir[x][y] == 'U')
            cdir = 2;
          else if (dir[x][y] == 'L')
            cdir = 3;
          int nx = x + dx[cdir];
          int ny = y + dy[cdir];
          if (!cache[nx][ny]) {
            x = nx, y = ny;
            continue;
          }
          if (loop_num[nx][ny] == -1) {
            int num = loops.size();
            int cnt = 0;
            auto it = prev(stk.end());
            while (true) {
              int cx = it->first;
              int cy = it->second;
              if (cx == nx && cy == ny) break;
              loop_num[cx][cy] = num;
              loop_section[cx][cy] = cnt++;
              it--;
            }
            int sz = cnt + 1;
            loops.push_back(stk);
            loop_sz.push_back(sz);
            while (true) {
              int cx = it->first;
              int cy = it->second;
              loop_num[cx][cy] = num;
              loop_section[cx][cy] = cnt++ % sz;
              if (it == stk.begin()) break;
              it--;
            }
          } else {
            int num = loop_num[nx][ny];
            int sz = loop_sz[num];
            int cnt = loop_section[nx][ny] + 1;
            loops[num].insert(loops[num].end(), stk.begin(), stk.end());
            auto it = prev(stk.end());
            while (true) {
              int cx = it->first;
              int cy = it->second;
              loop_num[cx][cy] = num;
              loop_section[cx][cy] = cnt++ % sz;
              if (it == stk.begin()) break;
              it--;
            }
          }
          break;
        }
      }
    for (int i = 0; i < loops.size(); i++) {
      int sz = loop_sz[i];
      vector<int> cnt(sz);
      all += sz;
      for (pair<int, int> it : loops[i]) {
        int x = it.first;
        int y = it.second;
        int section = loop_section[x][y];
        if (color[x][y] == '0') cnt[section]++;
      }
      for (int it : cnt)
        if (it) ans++;
    }
    cout << all << ' ' << ans << '\n';
  }
}

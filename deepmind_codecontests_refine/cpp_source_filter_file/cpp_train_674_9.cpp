#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int n, m, q;
int table[205][205];
pair<int, int> ab[10];
pair<int, int> nxt[205][205];
vector<pair<int, int> > prv[205][205];
int cycleIdx[205][205];
int cycleNum;
vector<pair<int, int> > cycle[205 * 205];
bool has[205 * 205][10];
string s;
int vis[205][205];
bool inCycle;
void setCycle(int x, int y) {
  if (vis[x][y] == 2) return;
  if (vis[x][y] == 1) {
    inCycle = true;
    cycle[cycleNum].push_back(make_pair(x, y));
    cycleIdx[x][y] = cycleNum;
    has[cycleNum][table[x][y]] = 1;
    vis[x][y] = 2;
    return;
  }
  vis[x][y] = 1;
  setCycle(nxt[x][y].first, nxt[x][y].second);
  if (vis[x][y] == 1 && inCycle) {
    cycle[cycleNum].push_back(make_pair(x, y));
    cycleIdx[x][y] = cycleNum;
    has[cycleNum][table[x][y]] = 1;
  } else if (vis[x][y] == 2)
    inCycle = false;
  vis[x][y] = 2;
}
void setPrev() {
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)m; j++) {
      if (cycleIdx[i][j] == -1) {
        prv[nxt[i][j].first][nxt[i][j].second].push_back(make_pair(i, j));
      }
    }
  }
}
bool query(string& s, int pos, int x, int y) {
  if (pos >= 0 && s[pos] - '0' == table[x][y]) pos--;
  if (pos == -1) return true;
  for (int i = 0; i < (int)prv[x][y].size(); i++) {
    if (query(s, pos, prv[x][y][i].first, prv[x][y][i].second)) return true;
  }
  return false;
}
void query(string& s, vector<int> fIdxs) {
  for (int i = 0; i < (int)cycleNum; i++) {
    int pos = -1;
    for (int j = 0; j < (int)10; j++) {
      if (fIdxs[j] != -1 && !has[i][j]) pos = max(pos, fIdxs[j]);
    }
    if (pos == -1) {
      cout << "Yes" << endl;
      return;
    }
    for (int j = 0; j < (int)cycle[i].size(); j++) {
      if (query(s, pos, cycle[i][j].first, cycle[i][j].second)) {
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
}
int main() {
  cycleNum = 0;
  memset(has, 0, sizeof(has));
  memset(vis, 0, sizeof(vis));
  memset(cycleIdx, -1, sizeof(cycleIdx));
  cin >> n >> m >> q;
  for (int i = 0; i < (int)n; i++) {
    cin >> s;
    for (int j = 0; j < (int)m; j++) {
      table[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i < (int)10; i++) cin >> ab[i].first >> ab[i].second;
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)m; j++) {
      int ni = i + ab[table[i][j]].first, nj = j + ab[table[i][j]].second;
      if (ni >= 0 && ni < n && nj >= 0 && nj < m)
        nxt[i][j] = make_pair(ni, nj);
      else
        nxt[i][j] = make_pair(i, j);
    }
  }
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)m; j++) {
      if (!vis[i][j]) {
        setCycle(i, j);
        if (cycle[cycleNum].size()) cycleNum++;
      }
    }
  }
  setPrev();
  for (int i = 0; i < (int)q; i++) {
    cin >> s;
    vector<int> idxs(10, -1);
    for (int j = s.length() - 1; j >= 0; j--) idxs[s[j] - '0'] = j;
    query(s, idxs);
  }
  return 0;
}

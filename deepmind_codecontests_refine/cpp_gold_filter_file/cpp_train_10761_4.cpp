#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long Hashimoto = 0, Kanna = 1;
  char I_Love = getchar();
  while (I_Love < '0' || I_Love > '9') {
    if (I_Love == '-') Kanna = -1;
    I_Love = getchar();
  }
  while (I_Love >= '0' && I_Love <= '9') {
    Hashimoto = Hashimoto * 10 + I_Love - '0';
    I_Love = getchar();
  }
  return Hashimoto * Kanna;
}
inline bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  return a.first > b.first;
}
int n, t;
vector<int> sav;
pair<int, pair<int, int> > pan[111111];
vector<int> g[111111];
int ind[111111];
queue<int> q;
int dp[111111];
int nn = 1;
int dat[1 << 20];
int lzy[1 << 20];
void upd(int l, int r, int val, int k, int a, int b) {
  if (l >= b || a >= r) return;
  if (l <= a && b <= r) {
    lzy[k] = dat[k] = val;
    return;
  }
  if (lzy[k] != -1) {
    dat[k * 2 + 1] = lzy[k * 2 + 1] = dat[k * 2 + 2] = lzy[k * 2 + 2] = lzy[k];
    lzy[k] = -1;
  }
  int mid = a + b >> 1;
  upd(l, r, val, k * 2 + 1, a, mid);
  upd(l, r, val, k * 2 + 2, mid, b);
  dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
}
int hah(int l, int r, int k, int a, int b) {
  if (l >= b || a >= r) return 0;
  if (l <= a && b <= r) {
    return dat[k];
  }
  if (lzy[k] != -1) {
    dat[k * 2 + 1] = lzy[k * 2 + 1] = dat[k * 2 + 2] = lzy[k * 2 + 2] = lzy[k];
    lzy[k] = -1;
  }
  int mid = a + b >> 1;
  return max(hah(l, r, k * 2 + 1, a, mid), hah(l, r, k * 2 + 2, mid, b));
}
void build(int l, int r, int v, int state) {
  if (l >= r) return;
  int u = hah(l, r, 0, 0, nn);
  if (!((pan[u].second.first < l && l <= pan[u].second.second) && !(state & 1)))
    if (!((pan[u].second.first <= r && r < pan[u].second.second) &&
          !(state & 2))) {
      if (max(pan[u].second.first, pan[v].second.first) !=
          min(pan[u].second.second, pan[v].second.second)) {
        g[u].push_back(v);
      }
    }
  if (l < pan[u].second.first) build(l, pan[u].second.first, v, state & 1);
  if (pan[u].second.second < r) build(pan[u].second.second, r, v, state & 2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  memset(dat, 0, sizeof(dat));
  memset(lzy, 0, sizeof(lzy));
  n = read();
  t = read();
  pan[0] = {t, {-(int)1e9, (int)1e9}};
  sav.push_back(-(int)1e9);
  sav.push_back((int)1e9);
  for (int i = 1; i < n + 1; i++) {
    int a = read(), b = read(), c = read();
    pan[i] = {a, {b, c}};
    sav.push_back(b);
    sav.push_back(c);
  }
  sort(sav.begin(), sav.end());
  ;
  sav.erase(unique(sav.begin(), sav.end()), sav.end());
  for (int i = 0; i < n + 1; i++) {
    pan[i].second.first =
        lower_bound(sav.begin(), sav.end(), pan[i].second.first) - sav.begin();
    pan[i].second.second =
        lower_bound(sav.begin(), sav.end(), pan[i].second.second) - sav.begin();
  }
  sort(pan, pan + n + 1, cmp);
  while (nn <= sav.size()) nn <<= 1;
  for (int i = 1; i < n + 1; i++) {
    build(pan[i].second.first, pan[i].second.second, i, 3);
    upd(pan[i].second.first, pan[i].second.second, i, 0, 0, nn);
  }
  for (int i = 0; i < n + 1; i++) {
    sort(g[i].begin(), g[i].end());
    ;
    g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    for (int j = 0; j < g[i].size(); j++) {
      int to = g[i][j];
      ind[to]++;
    }
  }
  if (ind[0] != 0) return -1;
  q.push(0);
  dp[0] = 2 * (int)1e9;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < g[x].size(); i++) {
      int to = g[x][i];
      dp[to] = max(
          dp[to],
          min(dp[x], sav[min(pan[x].second.second, pan[to].second.second)] -
                         sav[max(pan[x].second.first, pan[to].second.first)]));
      ind[to]--;
      if (!ind[to]) q.push(to);
    }
  }
  int ans = 0;
  for (int i = 0; i < n + 1; i++) {
    if (g[i].size() == 0) ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}

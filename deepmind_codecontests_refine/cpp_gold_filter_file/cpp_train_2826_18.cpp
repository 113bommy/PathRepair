#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int N = 1e5 + 5, P = 350, Q = 350;
int p[N], s[N], b[N], inc[N], pos[N], pref[N], ans[N], q[N], t[2][N], tp[2][N];
int n, m;
multiset<int> st[2][N];
void upd(int h, int x, int y) {
  t[h][x] += y;
  tp[h][x / Q] += y;
}
int que(int h, int x) {
  int y = 0, s = 0;
  while ((y + 1) * Q - 1 <= x) s += tp[h][y++];
  y *= Q;
  while (y <= x) s += t[h][y++];
  return s;
}
int x = 0, y = -1, cur = 0;
void handle(vector<int> &w, int rev) {
  if (w[1] ^ rev) {
    if (w[2] <= y) {
      upd(0, w[3], 1);
    } else {
      upd(1, w[4], 1);
    }
    st[0][w[2]].insert(w[3]);
    st[1][w[2]].insert(w[4]);
  } else {
    if (w[2] <= y) {
      upd(0, w[3], -1);
    } else {
      upd(1, w[4], -1);
    }
    st[0][w[2]].erase(st[0][w[2]].find(w[3]));
    st[1][w[2]].erase(st[1][w[2]].find(w[4]));
  }
}
void solve() {
  for (int i = 0; i < N; i++) {
    st[0][i].clear();
    st[1][i].clear();
  }
  memset(t, 0, sizeof(t));
  memset(tp, 0, sizeof(tp));
  vector<vector<int>> v;
  vector<int> spb1, spb2, sb;
  for (int i = 0; i < n; i++) {
    spb1.push_back(p[i] - b[i]);
    spb2.push_back(p[i] + b[i]);
    sb.push_back(b[i]);
  }
  sort(sb.begin(), sb.end());
  sb.erase(unique(sb.begin(), sb.end()), sb.end());
  sort(spb1.begin(), spb1.end());
  spb1.erase(unique(spb1.begin(), spb1.end()), spb1.end());
  sort(spb2.begin(), spb2.end());
  spb2.erase(unique(spb2.begin(), spb2.end()), spb2.end());
  for (int i = 0; i < n; i++) {
    int j = lower_bound(sb.begin(), sb.end(), b[i]) - sb.begin(),
        k = lower_bound(spb1.begin(), spb1.end(), p[i] - b[i]) - spb1.begin(),
        z = lower_bound(spb2.begin(), spb2.end(), p[i] + b[i]) - spb2.begin();
    v.push_back({p[i], 1, j, k, z});
    v.push_back({s[i] + 1, 0, j, k, z});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    pos[i] = upper_bound(v.begin(), v.end(), vector<int>{inc[i] + 1, -1}) -
             v.begin();
    q[i] = i;
  }
  sort(q, q + m, [](int x, int y) {
    int px = pos[x] / P;
    if (px == pos[y] / P) {
      if (px & 1) return pref[x] < pref[y];
      return pref[x] > pref[y];
    }
    return pos[x] < pos[y];
  });
  x = 0, y = -1, cur = 0;
  for (int i = 0; i < m; i++) {
    int j = q[i];
    while (x < pos[j]) {
      handle(v[x], 0);
      x++;
    }
    while (x > pos[j]) {
      x--;
      handle(v[x], 1);
    }
    while (y < (int)sb.size() - 1 && sb[y + 1] <= pref[j]) {
      y++;
      for (int k : st[0][y]) upd(0, k, 1);
      for (int k : st[1][y]) upd(1, k, -1);
    }
    while (y >= 0 && sb[y] > pref[j]) {
      for (int k : st[0][y]) upd(0, k, -1);
      for (int k : st[1][y]) upd(1, k, 1);
      y--;
    }
    int k =
        upper_bound(spb1.begin(), spb1.end(), inc[j] - pref[j]) - spb1.begin();
    ans[j] += que(0, k - 1);
    k = upper_bound(spb2.begin(), spb2.end(), inc[j] + pref[j]) - spb2.begin();
    ans[j] += que(1, k - 1);
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> inc[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> pref[i];
  }
  solve();
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MXN = 300005;
const int MXV = 1000005;
int n, m;
pair<int, int> segm[MXN];
int nleft[MXV];
int nright[MXV];
vector<int> Q[MXN];
int ans[MXN];
int fwtall[MXV];
int fwted[MXV];
static void addv(int* ar, int pos, int v) {
  while (pos < MXV) {
    ar[pos] += v;
    pos |= pos + 1;
  }
}
static int getv(int* ar, int l, int r) {
  if (l == 0) {
    int ans = 0;
    while (r >= 0) {
      ans += ar[r];
      r = (r & (r + 1)) - 1;
    }
    return ans;
  } else {
    return getv(ar, 0, r) - getv(ar, 0, l - 1);
  }
}
struct Event {
  int pos;
  int type;
  int d1;
  int d2;
};
Event ev[MXN * 3];
static bool cmpev(const Event& a, const Event& b) {
  if (a.pos != b.pos) return a.pos < b.pos;
  return a.type < b.type;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> segm[i].first >> segm[i].second;
    nleft[segm[i].second]++;
    nright[segm[i].first]++;
  }
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    Q[i].resize(t);
    for (int j = 0; j < t; j++) {
      cin >> Q[i][j];
    }
  }
  for (int i = 1; i < MXV; i++) {
    nleft[i] += nleft[i - 1];
  }
  for (int i = MXV - 2; i >= 0; --i) {
    nright[i] += nright[i + 1];
  }
  for (int i = 0; i < m; i++) {
    ans[i] += n;
    ans[i] -= nleft[Q[i][0] - 1];
    ans[i] -= nright[1 + Q[i][Q[i].size() - 1]];
  }
  int evc = 0;
  for (int i = 0; i < n; i++) {
    ev[evc].type = 3;
    ev[evc].pos = segm[i].first;
    evc++;
    ev[evc].type = 1;
    ev[evc].pos = segm[i].second;
    ev[evc].d1 = segm[i].first;
    evc++;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 1; j < Q[i].size(); j++) {
      if (Q[i][j] - Q[i][j - 1] >= 3) {
        ev[evc].type = 2;
        ev[evc].pos = Q[i][j] - 1;
        ev[evc].d1 = i;
        ev[evc].d2 = Q[i][j - 1] + 1;
        evc++;
      }
    }
  }
  sort(ev, ev + evc, cmpev);
  for (int i = 0; i < evc; i++) {
    Event& e = ev[evc];
    if (e.type == 1) {
      addv(fwtall, e.pos, 1);
      addv(fwted, e.pos, 1);
    } else if (e.type == 2) {
      int cnt = getv(fwtall, e.d2, e.pos) - getv(fwted, e.d2, e.pos);
      ans[e.d1] -= cnt;
    } else if (e.type == 3) {
      addv(fwted, e.d1, -1);
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}

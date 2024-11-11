#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
pair<int, int> t[4 * MAXN];
void update(int x, int vl, int vr, int pos, int val) {
  if (pos < vl || pos > vr)
    return;
  else if (vl == vr) {
    t[x].first++;
    t[x].second = val;
  } else {
    int m = (vl + vr) / 2;
    update(x * 2, vl, m, pos, val);
    update(x * 2 + 1, m + 1, vr, pos, val);
    t[x].first++;
  }
}
int srch(int x, int vl, int vr, int pos) {
  if (vl == vr) {
    return t[x].second;
  } else {
    int m = (vl + vr) / 2;
    int s1, s2;
    s1 = t[x * 2].first;
    s2 = t[x * 2 + 1].first;
    if (s1 >= pos) {
      srch(x * 2, vl, m, pos);
    } else {
      pos -= s1;
      srch(x * 2 + 1, m + 1, vr, pos);
    }
  }
}
void debug(int v, int vl, int vr) {
  cout << "v=" << v << "  vl=" << vl << "   vr=" << vr << "  t=" << t[v].first
       << ", " << t[v].second << endl;
  if (vl != vr) {
    int m = (vl + vr) / 2;
    debug(v * 2, vl, m);
    debug(v * 2 + 1, m + 1, vr);
  }
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pair<int, int> p = {x, -i};
    v[i] = p;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
  }
  int m;
  cin >> m;
  vector<pair<pair<int, int>, int> > ask(m);
  vector<int> ans(m);
  int u = 0;
  while (m--) {
    int k, pos;
    cin >> k >> pos;
    pair<int, int> p = {k, pos};
    pair<pair<int, int>, int> q = {p, u};
    ask[u] = q;
    u++;
  }
  sort(ask.begin(), ask.end());
  int j = 0;
  for (int i = 1; i <= n; i++) {
    int ps = -v[i - 1].second;
    update(1, 0, MAXN, ps, v[i - 1].first);
    while (j < u && ask[j].first.first == i) {
      pair<int, int> tmp = ask[j].first;
      int d = ask[j].second;
      ans[d] = srch(1, 0, MAXN, tmp.second);
      j++;
    }
  }
  for (int i = 0; i < u; i++) cout << ans[i] << "\n";
}
int main() { solve(); }

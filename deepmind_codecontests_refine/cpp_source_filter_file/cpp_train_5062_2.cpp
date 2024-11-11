#include <bits/stdc++.h>
using namespace std;
void topsort(vector<vector<long long> > &g, long long v, vector<bool> &used,
             vector<long long> &verts) {
  used[v] = 1;
  for (long long i = 0; i < g[v].size(); i++) {
    if (!used[g[v][i]]) {
      topsort(g, g[v][i], used, verts);
    }
  }
  verts.push_back(v);
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long> > g(2 * m), gr(2 * m);
  vector<long long> s, t;
  long long sz;
  cin >> sz;
  s.assign(sz, 0);
  for (long long i = 0; i < sz; i++) {
    cin >> s[i];
    s[i]--;
  }
  bool flag = 0;
  for (long long i = 0; i < n - 1; i++) {
    cin >> sz;
    t.assign(sz, 0);
    for (long long j = 0; j < sz; j++) {
      cin >> t[j];
      t[j]--;
    }
    bool curflag = 0;
    for (long long j = 0; j < min(s.size(), t.size()); j++) {
      if (s[j] != t[j]) {
        curflag = 1;
        if (s[j] < t[j]) {
          g[s[j] * 2].push_back(t[j] * 2);
          g[t[j] * 2 + 1].push_back(s[j] * 2 + 1);
          gr[t[j] * 2].push_back(s[j] * 2);
          gr[s[j] * 2 + 1].push_back(t[j] * 2 + 1);
        } else {
          g[s[j] * 2 + 1].push_back(t[j] * 2);
          g[t[j] * 2].push_back(s[j] * 2 + 1);
          g[s[j] * 2].push_back(s[j] * 2 + 1);
          gr[t[j] * 2 + 1].push_back(s[j] * 2);
          gr[s[j] * 2].push_back(t[j] * 2 + 1);
          gr[s[j] * 2 + 1].push_back(s[j] * 2);
        }
        break;
      }
    }
    if (curflag == 0 && s.size() > t.size()) {
      flag = 1;
    }
    s = t;
  }
  vector<long long> ts;
  vector<bool> used(2 * m, 0);
  ts.reserve(2 * m);
  for (long long i = 0; i < 2 * m; i++) {
    if (!used[i]) topsort(g, i, used, ts);
  }
  reverse(ts.begin(), ts.end());
  vector<vector<long long> > comps;
  used.assign(2 * m, 0);
  vector<long long> pos(2 * m, -1);
  for (long long i = 0; i < 2 * m; i++) {
    comps.push_back(vector<long long>());
    if (!used[ts[i]]) {
      topsort(gr, ts[i], used, comps[i]);
    }
    for (long long j = 0; j < comps[i].size(); j++) {
      pos[comps[i][j]] = i;
      if (pos[comps[i][j]] == pos[comps[i][j] ^ 1]) {
        flag = 1;
      }
    }
  }
  vector<long long> answ;
  if (flag) {
    cout << "No";
  } else {
    for (long long i = 0; i < m * 2; i += 2) {
      if (pos[i + 1] > pos[i]) {
        answ.push_back(i / 2 + 1);
      }
    }
    cout << "Yes" << endl;
    cout << answ.size() << endl;
    for (auto &x : answ) {
      cout << x << " ";
    }
  }
  cin >> n;
  return 0;
}

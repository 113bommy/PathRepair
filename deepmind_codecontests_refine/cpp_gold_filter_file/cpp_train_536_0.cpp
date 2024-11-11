#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> e;
int root(vector<int> &p, vector<int> &s, int r) {
  if (e[r].size() == 1 and p[r] != -1)
    return s[r] = 1;
  else {
    s[r] = 0;
    for (int c : e[r]) {
      if (p[r] != c) {
        p[c] = r;
        s[r] += root(p, s, c);
      }
    }
    return ++s[r];
  }
}
int val(int a, int b) { return (a + 1) * (b)-1; }
void output(vector<int> &p, vector<int> &values, int r, int &count, int &mul) {
  values[r] = count;
  cout << p[r] + 1 << " " << r + 1 << " " << values[r] - values[p[r]] << "\n";
  count += mul;
  for (int c : e[r])
    if (p[r] != c) output(p, values, c, count, mul);
}
int main() {
  int n;
  cin >> n;
  int limit = (2 * n * n) / 9;
  vector<int> blank;
  for (int i = 0; i < n; i++) e.push_back(blank);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (int rc = 0; rc < n; rc++) {
    int r = rc;
    vector<int> p(n, -1);
    vector<int> s(n, 1);
    root(p, s, r);
    int maxp, maxv = 0;
    for (int i = 0; i < e[r].size(); i++) {
      int c = e[r][i];
      if (s[c] > maxv) {
        maxv = s[c];
        maxp = i;
      }
    }
    if (maxv > n / 2 and val(maxv, n - maxv) < limit) continue;
    vector<bool> keep(e[r].size(), false);
    keep[maxp] = true;
    for (int i = 0; i < e[r].size(); i++) {
      if (val(maxv, n - maxv) >= limit) break;
      if (i != maxp) {
        maxv += s[e[r][i]];
        keep[i] = true;
      }
    }
    int count = 1, mul = 1;
    vector<int> values(n, 0);
    for (int i = 0; i < e[r].size(); i++)
      if (keep[i]) output(p, values, e[r][i], count, mul);
    mul = count;
    for (int i = 0; i < e[r].size(); i++)
      if (!keep[i]) output(p, values, e[r][i], count, mul);
    return 0;
  }
  return 1;
}

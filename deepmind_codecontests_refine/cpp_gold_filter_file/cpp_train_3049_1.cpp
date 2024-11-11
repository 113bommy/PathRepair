#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 1;
int m, n;
pair<long long, long long> pu[M], pv[M];
vector<pair<long long, long long> > v;
pair<long long, long long> lca(pair<long long, long long> x,
                               pair<long long, long long> y) {
  for (int i = 29; i >= 0; i--) {
    int qx = 0, qy = 0;
    if ((x.first >> i) & 1) qx++;
    if ((x.second >> i) & 1) qx += 2;
    if ((y.first >> i) & 1) qy++;
    if ((y.second >> i) & 1) qy += 2;
    if (qx == qy) continue;
    if (qx + qy == 3) {
      x.first &= (1 << 30) - (1 << (i + 1));
      x.second &= (1 << 30) - (1 << (i + 1));
      return x;
    }
    if (qx == 0) {
      swap(x, y);
      swap(qx, qy);
    }
    x.first &= (1 << 30) - (1 << (i + 1));
    x.second &= (1 << 30) - (1 << (i + 1));
    if (qx == 1)
      x.first |= (1 << i) - 1;
    else
      x.second |= (1 << i) - 1;
  }
  return x;
}
bool cmp(pair<long long, long long> x, pair<long long, long long> y) {
  for (int i = 29; i >= 0; i--) {
    int qx = 0, qy = 0;
    if ((x.first >> i) & 1) qx++;
    if ((x.second >> i) & 1) qx += 2;
    if ((y.first >> i) & 1) qy++;
    if ((y.second >> i) & 1) qy += 2;
    if (qx == qy) continue;
    if (qx == 2 || qy == 2) return (qy == 2);
    if (qx == 0) return ((x.second & ((1 << i) - 1)) == 0);
    return ((y.second & ((1 << i) - 1)) != 0);
  }
  return false;
}
pair<long long, long long> tn[M];
vector<int> ch[M];
int p[M];
int f[M], g[M];
map<pair<long long, long long>, int> mp;
map<int, int> cal;
void dfs(int id) {
  int fun = 0;
  for (auto c : ch[id]) {
    dfs(c);
    if (f[c] > 0) {
      cal[tn[c].first + tn[c].second] ^= 1;
      cal[tn[id].first + tn[id].second + 1] ^= 1;
    }
    fun += f[c];
  }
  if (fun > 0 || f[id] > 0 || g[id] > 0) {
    cal[tn[id].first + tn[id].second] ^= 1;
    cal[tn[id].first + tn[id].second + 1] ^= 1;
  }
  f[id] += fun;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> pu[i].first >> pu[i].second;
    cin >> pv[i].first >> pv[i].second;
    v.push_back(pu[i]);
    v.push_back(pv[i]);
  }
  sort(v.begin(), v.end(), cmp);
  v.erase(unique(v.begin(), v.end()), v.end());
  int x = v.size();
  for (int i = 0; i < x - 1; i++) {
    v.push_back(lca(v[i], v[i + 1]));
  }
  sort(v.begin(), v.end(), cmp);
  v.erase(unique(v.begin(), v.end()), v.end());
  stack<int> s;
  for (auto c : v) {
    while (!s.empty() && lca(tn[s.top()], c) != tn[s.top()]) {
      s.pop();
    }
    tn[++n] = c;
    if (!s.empty()) {
      ch[s.top()].push_back(n);
      p[n] = s.top();
    }
    s.push(n);
  }
  for (int i = 1; i <= n; i++) {
    mp[tn[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    if (pu[i] == pv[i]) {
      g[mp[pu[i]]]++;
    }
    f[mp[pu[i]]]++;
    f[mp[pv[i]]]++;
    f[mp[lca(pu[i], pv[i])]] -= 2;
  }
  dfs(1);
  int ans = 0;
  for (auto c : cal) {
    if (c.first != 0) ans += c.second;
  }
  cout << ans << '\n';
}

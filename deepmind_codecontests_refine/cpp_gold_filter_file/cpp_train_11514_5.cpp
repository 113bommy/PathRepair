#include <bits/stdc++.h>
using namespace std;
const int MDSZ = 2, MD[4] = {1000000007, 1018199999, 1062599999, 701},
          KY[4] = {317087, 317089, 317123, 97};
inline int pw(int b, int e, int m) {
  int t = 1;
  while (e) {
    if (e & 1) {
      t = ((long long)t * b) % m;
    }
    b = ((long long)b * b) % m;
    e >>= 1;
  }
  return t;
}
struct hsh {
  vector<int> pref[MDSZ];
  int tp[MDSZ] = {};
  inline void gen(vector<int> &v) {
    for (int i = 0; i < MDSZ; i++) {
      tp[i] = 1;
      pref[i].push_back(0);
    }
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < MDSZ; j++) {
        pref[j].push_back((pref[j].back() + (long long)v[i] * tp[j]) % MD[j]);
        tp[j] = ((long long)tp[j] * KY[j]) % MD[j];
      }
    }
  }
  inline int gimme(int rem, int w) {
    return (pref[w][rem] +
            ((long long)pref[w].back() - pref[w][rem + 1] + MD[w]) % MD[w] *
                pw(KY[w], MD[w] - 2, MD[w])) %
           MD[w];
  }
};
inline bool isSame(hsh &h1, int rem1, hsh &h2, int rem2) {
  bool b = 1;
  for (int i = 0; i < MDSZ; i++) b &= (h1.gimme(rem1, i) == h2.gimme(rem2, i));
  return b;
}
int n, m, pr[300001] = {}, num[300001] = {}, cr = 0;
vector<vector<int>> adj;
vector<hsh> node;
vector<set<int>> nw;
int fn(int x) { return pr[x] = (pr[x] != x) ? fn(pr[x]) : x; }
inline void jn(int a, int b) {
  a = fn(a), b = fn(b);
  if (a != b) {
    pr[b] = a;
  }
}
void dfs(int u, int p) {
  num[u] = ++cr;
  for (auto v : nw[u]) {
    if (v ^ p) dfs(v, u);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    pr[i] = i;
    adj.push_back(vector<int>());
    node.push_back(hsh());
    nw.push_back(set<int>());
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }
  for (int i = 0; i < n; i++) {
    sort(adj[i].begin(), adj[i].end());
    node[i].gen(adj[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      int v = adj[i][j];
      if (v < i) {
        int idx2 =
            lower_bound(adj[v].begin(), adj[v].end(), i) - adj[v].begin();
        if (isSame(node[i], j, node[v], idx2)) {
          jn(i, v);
        }
      } else {
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (auto v : adj[i]) {
      if (fn(i) == fn(v)) {
        continue;
      }
      nw[fn(i)].insert(fn(v));
    }
  }
  bool sz = 1;
  for (int i = 0; i < n; i++) {
    sz &= (nw[i].size() < 3);
  }
  if (sz) {
    for (int i = 0; i < n; i++) {
      if (num[i] == 0 && nw[i].size() < 2) {
        dfs(i, -1);
        ++cr;
      }
    }
    for (int i = 0; i < n; i++) {
      if (num[i] == 0) {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      cout << num[fn(i)];
      if (i < n - 1) {
        cout << " ";
      }
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}

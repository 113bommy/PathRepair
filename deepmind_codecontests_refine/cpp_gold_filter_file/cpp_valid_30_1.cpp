#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5e4 + 5, M = 1e6 + 5, mod = 1e9 + 7;
int p[M], a[N], fix[M], n, q;
vector<int> v, V[M];
map<int, int> cnt[M];
void _() {
  for (int i = 2; i <= M - 4; i++) {
    if (!p[i]) {
      p[i] = i;
      v.push_back(i);
    }
    for (int j = 0; j < v.size(); j++) {
      if (v[j] > p[i] || v[j] > (M - 4) / i) break;
      p[v[j] * i] = v[j];
    }
  }
}
void dfs(int u, int p) {
  fix[u] = p;
  for (int i = 0; i < V[u].size(); i++) {
    if (!fix[V[u][i]]) dfs(V[u][i], p);
  }
}
void go(int b, vector<int> &v) {
  while (b - 1) {
    int c = p[b];
    while (b % c == 0) b /= c;
    v.push_back(c);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  _();
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vector<int> d;
    go(a[i], d);
    for (int i = 1; i < d.size(); i++) {
      V[d[i]].push_back(d[i - 1]);
      V[d[i - 1]].push_back(d[i]);
    }
  }
  for (int i = 0; i < v.size(); i++) {
    if (fix[v[i]]) continue;
    dfs(v[i], v[i]);
  }
  for (int i = 1; i <= n; i++) {
    vector<int> d;
    go(a[i], d);
    vector<int> d1;
    go(a[i] + 1, d1);
    for (int i = 0; i < d1.size(); i++) {
      for (int j = 0; j < d1.size(); j++) {
        cnt[fix[d1[i]]][fix[d1[j]]] = 1;
      }
      for (int j = 0; j < d.size(); j++) {
        cnt[fix[d1[i]]][fix[d[j]]] = cnt[fix[d[j]]][fix[d1[i]]] = 1;
      }
    }
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (fix[p[a[u]]] == fix[p[a[v]]])
      cout << 0 << " ";
    else if (fix[p[a[u]]] == fix[2] || fix[p[a[v]]] == fix[2])
      cout << 1 << " ";
    else {
      vector<int> d1, d2;
      go(a[u], d1);
      go(a[v], d2);
      int first = 2;
      if (cnt[fix[p[a[u]]]][fix[p[a[v]]]])
        cout << 1 << " ";
      else
        cout << first << " ";
    }
  }
}

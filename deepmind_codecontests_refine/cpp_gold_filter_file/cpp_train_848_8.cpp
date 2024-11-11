#include <bits/stdc++.h>
using namespace std;
vector<int> parent(500000 + 1, 0);
vector<int> rnk(500000 + 1, 0);
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
  parent[v] = v;
  rnk[v] = 0;
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int>> edge;
    vector<int> adj[3 * n + 1];
    for (long long i = 1; i <= m; i++) {
      long long a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
      edge.push_back(make_tuple(0, a, b, i));
    }
    vector<int> id(3 * n + 1);
    for (long long i = 1; i <= 3 * n; i++) id[i] = (long long)(adj[i]).size();
    for (auto x : edge) {
      get<0>(x) = id[get<1>(x)] + id[get<2>(x)];
    }
    sort((edge).begin(), (edge).end());
    vector<pair<int, int>> vorder;
    for (long long i = 1; i <= 3 * n; i++) vorder.push_back({id[i], i});
    sort((vorder).begin(), (vorder).end());
    int curr = 0;
    vector<bool> marked(3 * n + 1, false);
    vector<int> ans;
    for (auto x : edge) {
      int a = get<1>(x);
      int b = get<2>(x);
      int idx = get<3>(x);
      if (!marked[a] && !marked[b]) {
        curr++;
        ans.push_back(idx);
        marked[a] = marked[b] = true;
        if (curr == n) {
          cout << "Matching" << '\n';
          for (int u : ans) cout << u << " ";
          cout << '\n';
          goto done;
        }
      }
    }
    cout << "IndSet" << '\n';
    curr = 0;
    for (long long i = 1; i <= 3 * n; i++)
      if (!marked[i] && curr != n) {
        cout << i << " ";
        curr++;
      }
    cout << '\n';
  done:;
  }
  return 0;
}

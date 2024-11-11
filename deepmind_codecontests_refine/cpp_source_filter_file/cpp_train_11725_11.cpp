#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, size, lcount, ances;
  vector<int> child;
  node() : l(0), size(0), lcount(0), ances(0) {}
};
int st[200001], ed[200001], cnt = 1;
void dfs(vector<node> &graph, int root) {
  st[root] = cnt++;
  for (int i = 0; i < graph[root].child.size(); i++)
    dfs(graph, graph[root].child[i]);
  ed[root] = cnt - 1;
}
int seg[4 * 200001], lazy[4 * 200001];
void update(int n, int s, int e, int l, int r) {
  if (lazy[n] % 2 != 0) {
    seg[n] = e - s + 1 - seg[n];
    if (e != s) {
      lazy[2 * n]++;
      lazy[2 * n + 1]++;
    }
    lazy[n] = 0;
  }
  if (s > r || e < l) return;
  if (s >= l && e <= r) {
    seg[n] = e - s + 1 - seg[n];
    if (e != s) {
      lazy[2 * n]++;
      lazy[2 * n + 1]++;
    }
    lazy[n] = 0;
    return;
  }
  int mid = s + e >> 1;
  update(2 * n, s, mid, l, r);
  update(2 * n + 1, mid + 1, e, l, r);
  seg[n] = seg[2 * n] + seg[2 * n + 1];
}
int query(int n, int s, int e, int l, int r) {
  if (lazy[n] % 2 != 0) {
    seg[n] = e - s + 1 - seg[n];
    if (e != s) {
      lazy[2 * n]++;
      lazy[2 * n + 1]++;
    }
    lazy[n] = 0;
  }
  if (s > r || e < l) return 0;
  if (s >= l && e <= r) return seg[n];
  int mid = s + e >> 1;
  return query(2 * n, s, mid, l, r) + query(2 * n + 1, mid + 1, e, l, r);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<node> graph(n + 1, node());
  for (int a, i = 1; i < n; i++) {
    cin >> a;
    graph[a].child.push_back(i + 1);
    graph[i + 1].ances = a;
  }
  dfs(graph, 1);
  for (int a, i = 1; i <= n; i++) {
    cin >> a;
    if (a == 1) {
      update(1, 1, n, st[i], st[i]);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    if (s[0] == 'g') {
      cin >> s;
      int m = stoi(s);
      cout << query(1, 1, n, st[m], ed[m]) << endl;
    } else {
      cin >> s;
      int m = stoi(s);
      update(1, 1, n, st[m], st[m]);
    }
  }
}

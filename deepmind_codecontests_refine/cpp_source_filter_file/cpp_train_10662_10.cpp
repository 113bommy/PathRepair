#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000 + 200;
pair<int, int> v[4 * MAX_N];
pair<int, int> flag[4 * MAX_N];
vector<int> adj[MAX_N];
int arr[MAX_N], MIN[4 * MAX_N], m, n, ans, s[MAX_N], e[MAX_N], h[MAX_N], t;
bool mark[MAX_N];
void dfs(int u) {
  mark[u] = true;
  s[u] = t;
  for (int i = 0; i < adj[u].size(); i++) {
    int w = adj[u][i];
    if (!mark[w]) {
      h[w] = h[u] + 1;
      dfs(w);
    }
  }
  e[u] = t;
  t++;
}
void make(int node, int l, int r) {
  v[node].first = l;
  v[node].second = r;
  if (l == r) return;
  int mid = (r + l) / 2;
  make(2 * node, l, mid);
  make(2 * node + 1, mid + 1, r);
}
void change(int node, int l, int r, int st, int en, int h, int val) {
  if (l == st && r == en) {
    if (h % 2 == 0)
      flag[node].first += val;
    else
      flag[node].second += val;
    return;
  }
  int mid = (r + l) / 2;
  if (en <= mid) {
    change(2 * node, l, mid, st, en, h, val);
    return;
  }
  if (mid < st) {
    change(2 * node + 1, mid + 1, r, st, en, h, val);
    return;
  }
  change(2 * node, l, mid, st, mid, h, val);
  change(2 * node + 1, mid + 1, r, mid + 1, en, h, val);
}
void FIND(int node, int l, int r, int tar) {
  if (l == r && r == e[tar]) {
    if (h[tar] % 2 == 0) {
      ans += flag[node].first;
      ans -= flag[node].second;
    } else {
      ans -= flag[node].first;
      ans += flag[node].second;
    }
    return;
  }
  int mid = (r + l) / 2;
  if (e[tar] <= mid) {
    if (h[tar] % 2 == 0) {
      ans += flag[node].first;
      ans -= flag[node].second;
    } else {
      ans -= flag[node].first;
      ans += flag[node].second;
    }
    FIND(2 * node, l, mid, tar);
    return;
  } else {
    if (h[tar] % 2 == 0) {
      ans += flag[node].first;
      ans -= flag[node].second;
    } else {
      ans -= flag[node].first;
      ans += flag[node].second;
    }
    FIND(2 * node + 1, mid + 1, r, tar);
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  t = 1;
  dfs(1);
  make(1, 1, n);
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    if (a == 1) {
      int b, c;
      cin >> b >> c;
      change(1, 1, n, s[b], e[b], h[b], c);
    } else {
      int b;
      ans = 0;
      cin >> b;
      FIND(1, 1, n, b);
      cout << ans + arr[b];
    }
  }
}

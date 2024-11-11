#include <bits/stdc++.h>
using namespace std;
long long const INF = 2147483647, R_INF = 9223372036854775807, MOD = 1e9 + 7;
const int N = 4e5 + 1, M = 6e1 + 1;
vector<int> adj[N];
long long SG[N * 2], lzy[N * 2], st[N], en[N];
int ctr;
void change(int cur, long long val) {
  SG[cur] = val;
  lzy[cur] = val;
}
void push(int cur) {
  if (lzy[cur]) {
    change(cur * 2, lzy[cur]);
    change(cur * 2 + 1, lzy[cur]);
    lzy[cur] = 0;
  }
}
void pull(int cur) { SG[cur] = SG[cur * 2] | SG[cur * 2 + 1]; }
void update(int a, int b, long long val, int cur = 1, int l = 1, int r = N) {
  if (l > b || r < a) return;
  if (l >= a && r <= b) {
    change(cur, val);
    return;
  }
  push(cur);
  int m = (l + r) / 2;
  update(a, b, val, cur * 2, l, m);
  update(a, b, val, cur * 2 + 1, m + 1, r);
  pull(cur);
}
long long query(int a, int b, int cur = 1, int l = 1, int r = N) {
  if (l > b || r < a) return 0;
  if (l >= a && r <= b) return SG[cur];
  push(cur);
  int m = (l + r) / 2;
  return query(a, b, cur * 2, l, m) | query(a, b, cur * 2 + 1, m + 1, r);
}
void dfs(int cur, int par) {
  st[cur] = ++ctr;
  for (int u : adj[cur])
    if (u != par) dfs(u, cur);
  en[cur] = ctr;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  vector<int> input(n);
  for (int &i : input) cin >> i;
  for (int i = (1); i < (n); i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 1);
  for (int i = (1); i < (n + 1); i++)
    update(st[i], en[i], (1LL << input[i - 1]));
  while (q--) {
    int tag, x, y;
    cin >> tag;
    if (tag == 1) {
      cin >> x >> y;
      update(st[x], en[x], (1LL << y));
    } else {
      cin >> x;
      cout << __builtin_popcountll(query(st[x], en[x])) << '\n';
    }
  }
}

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
const ll inf = (1e18);
const ll mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }
struct __INIT {
  __INIT() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} __init;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int main() {
  int n, m;
  cin >> n >> m;
  V<V<int>> graph(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }
  int d = 0, memo;
  for (int i = 0; i < n; i++) {
    if (d < graph[i].size()) {
      memo = i;
      d = graph[i].size();
    }
  }
  queue<int> q;
  q.push(memo);
  V<bool> used(n, false);
  used[memo] = true;
  V<pair<ll, ll>> ans;
  while (q.size()) {
    int now = q.front();
    q.pop();
    for (int v : graph[now]) {
      if (used[v]) continue;
      used[v] = true;
      q.push(v);
      ans.push_back(pair<ll, ll>(now + 1, v + 1));
    }
  }
  for (auto p : ans) cout << p.first << " " << p.second << endl;
}

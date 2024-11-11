#include <bits/stdc++.h>
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
long long int gcd(long long int a, long long int b) {
  return (a ? gcd(b % a, a) : b);
}
long long int modPow(long long int a, long long int b, long long int MOD) {
  long long int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % MOD;
    }
    b /= 2;
    y = (y * y) % MOD;
  }
  return x;
}
long long int modInverse(long long int a, long long int p) {
  return modPow(a, p - 2, p);
}
using namespace std;
const int N = 3e5 + 5;
vector<pair<int, int> > adj[N];
int node_visited[N];
int edge_not_in_answer[N];
vector<int> ans;
int ispolice[N];
queue<int> myq;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, d, i, j, p, u, v;
  cin >> n >> k >> d;
  for (int i = (1); i <= (k); i++) {
    cin >> p;
    ispolice[p]++;
    myq.push(p);
    node_visited[p]++;
  }
  for (int i = (1); i <= (n - 1); i++) {
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  while (!myq.empty()) {
    v = myq.front();
    myq.pop();
    for (int i = 0; i < (adj[v].size()); i++) {
      if (!node_visited[adj[v][i].first]) {
        node_visited[adj[v][i].first] = 1;
        edge_not_in_answer[adj[v][i].second] = 1;
        myq.push(adj[v][i].first);
      }
    }
  }
  for (int i = (1); i <= (n - 1); i++) {
    if (!edge_not_in_answer[i]) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < (ans.size()); i++) cout << ans[i] << " ";
  return 0;
}

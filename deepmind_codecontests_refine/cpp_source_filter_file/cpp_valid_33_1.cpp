#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long ceile(long long &a, long long &b) { return (a / b) + ((a % b) != 0); }
class Graph {
 public:
  long long V;
  vector<vector<long long>> adj;
  Graph(long long V) {
    this->V = V;
    adj.resize(V, vector<long long>(0));
  }
  void addEdge(long long u, long long v) { adj[u].push_back(v); }
  bool DFS(long long s, long long V) {
    vector<bool> vis(V, 0);
    stack<long long> stack;
    stack.push(s);
    long long ans = 0;
    while (!stack.empty()) {
      s = stack.top();
      stack.pop();
      if (!vis[s]) {
        ans++;
        vis[s] = true;
      }
      for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!vis[*i]) stack.push(*i);
    }
    return ans == V;
  }
};
vector<long long> SieveOfEratosthenes(long long n) {
  vector<long long> ans;
  vector<bool> prime(n + 1, 1);
  for (long long p = 2; p * p <= n; p++)
    if (prime[p])
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
  for (long long p = 2; p <= n; p++)
    if (prime[p]) ans.push_back(p);
  return ans;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long &c : arr) cin >> c;
    long long ans = arr[0] * arr[1];
    for (long long i = 1; i < n - 1; i++) {
      ans = max(arr[i] * arr[i + 1], arr[i] * arr[i - 1]);
    }
    cout << ans << "\n";
  }
}

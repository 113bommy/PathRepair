#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int mod) {
  x %= mod;
  long long int r = 1;
  while (y > 0) {
    if (y & 1) r = r * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return r;
}
void Yes() {
  cout << "Yes"
       << "\n";
  return;
}
void No() {
  cout << "No"
       << "\n";
  return;
}
void YES() {
  cout << "YES"
       << "\n";
  return;
}
void NO() {
  cout << "NO"
       << "\n";
  return;
}
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
vector<long long int> sieve;
void Sieve(long long int n) {
  const long long int max_n = n;
  sieve.resize(max_n);
  for (long long int i = 0; i < max_n; ++i) sieve[i] = i;
  sieve[1] = -1;
  sieve[0] = -1;
  for (long long int i = 2; i <= max_n; i++)
    if (i == sieve[i])
      for (long long int j = 2 * i; j < max_n; j += i)
        if (sieve[j] == j) sieve[j] = i;
}
void dfs(vector<vector<int> >& adj, vector<int>& visited, vector<int>& parent,
         int u) {
  visited[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == 1) continue;
    parent[v] = u;
    dfs(adj, visited, parent, v);
  }
  return;
}
struct skills {
  long long int score;
  long long int frequency;
};
long long int modulo(long long int a, long long int b) {
  long long int c = (a % b);
  if (c >= 0)
    return c;
  else
    return c + b;
}
template <class T>
void prVec(vector<T> w) {
  cout << w.size() << "\n";
  for (int i = 0; i < int(w.size()) - 1; ++i) cout << w[i] << ' ';
  if (w.size()) cout << w[w.size() - 1] << "\n";
  return;
}
template <class T>
void prMat(vector<T> w) {
  for (int i = 0; i < int(w.size()); i++) prVec(w[i]);
  return;
}
bool comparePairs(const long long int a, const long long int b) {
  return a > b;
}
void solve() {
  long long int n, x;
  cin >> n >> x;
  long long int u, v;
  long long int count = 0;
  for (long long int(i) = 0; (i) < (n - 1); ++(i)) {
    cin >> u >> v;
    if (u == x || v == x) count++;
  }
  if (count == 1 || count == 0) {
    cout << "Ayush"
         << "\n";
    return;
  }
  if (n % 2 == 0)
    cout << "Ayush"
         << "\n";
  else
    cout << "Ashish"
         << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

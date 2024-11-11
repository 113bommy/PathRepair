#include <bits/stdc++.h>
using namespace std;
long long mult(long long a, long long b, long long p = (int)(1e9 + 7)) {
  return ((a % p) * (b % p)) % p;
}
long long add(long long a, long long b, long long p = (int)(1e9 + 7)) {
  return (a % p + b % p) % p;
}
long long fpow(long long n, long long k, long long p = (int)(1e9 + 7)) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
long long inv(long long a, long long p = (int)(1e9 + 7)) {
  return fpow(a, p - 2, p);
}
bool sa(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool fd(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
bool sd(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
const long long N = 150005;
vector<long long> v;
set<long long> s[N];
long long vis[N];
void dfs(long long node) {
  if (vis[node]) return;
  vis[node] = 1;
  v.push_back(node);
  for (long long next : s[node]) {
    dfs(node);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, x, y;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    s[x].insert(y);
    s[y].insert(x);
  }
  for (long long i = 0; i < n; i++) {
    vis[i] = 0;
  }
  for (long long i = 0; i < n; i++) {
    if (vis[i]) continue;
    v.clear();
    dfs(i);
    for (long long j = 0; j < v.size(); j++) {
      for (long long k = j + 1; k < v.size(); k++) {
        if ((s[v[j]].count(v[k])) == 0) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "Yes\n";
  return 0;
}

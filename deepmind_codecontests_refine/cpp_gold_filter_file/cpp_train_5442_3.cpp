#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first != b.first)
    return a.first < b.first;
  else
    return a.second > b.second;
}
long long ex(long long n, long long ans) {
  if (n == 1)
    return ans;
  else if (n % 2)
    return (ans % ((1000000007)) * ex(n / 2, (ans * ans) % (1000000007))) %
           (1000000007);
  else
    return ex(n / 2, (ans * ans) % (1000000007));
}
long long kmp(string x, long long m) {
  vector<long long> pi(m, 0);
  pi[0] = 0;
  long long j = 0;
  for (long long i = 1; i < m; i++) {
    j = pi[i - 1];
    while (j > 0 && x[i] != x[j]) j = pi[j - 1];
    if (x[j] == x[i]) j++;
    pi[i] = j;
  }
  return j;
}
string kmp1(string x, long long m) {
  vector<long long> pi(m, 0);
  pi[0] = 0;
  long long ma = 0;
  long long j = 0;
  long long pos = 0;
  for (long long i = 1; i < m; i++) {
    j = pi[i - 1];
    while (j > 0 && x[i] != x[j]) j = pi[j - 1];
    if (x[j] == x[i]) j++;
    pi[i] = j;
    if (x[i] == '#') pos = i;
  }
  long long p = pos;
  for (long long i = (pos); i < (m); ++i) {
    if (pi[i] > ma) {
      ma = pi[i];
      p = i;
    }
  }
  return x.substr(p - ma + 1, ma);
}
void dfs(vector<long long> adj[], long long fl[], long long i, long long& cn) {
  fl[i] = 1;
  cn++;
  for (long long j = (0); j < (adj[i].size()); ++j) {
    if (!fl[adj[i][j]]) {
      dfs(adj, fl, adj[i][j], cn);
    }
  }
}
int isp(long long x) {
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
struct Compare {
  bool operator()(long long const& p1, long long const& p2) {
    if (p1 < p2) {
      return true;
    }
    return false;
  }
};
void solve() {
  long long n;
  cin >> n;
  string x;
  cin >> x;
  long long a = 0, b = 0;
  if (n % 2) {
    for (long long i = 0; i < n; i += 2) (x[i] - '0') % 2 ? a++ : b++;
    if (a > 0)
      cout << 1;
    else
      cout << 2;
  } else {
    for (long long i = 1; i < n; i += 2) (x[i] - '0') % 2 ? a++ : b++;
    if (b > 0)
      cout << 2;
    else
      cout << 1;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t1 = 1;
  cin >> t1;
  while (t1--) {
    solve();
    cout << "\n";
    ;
  }
}

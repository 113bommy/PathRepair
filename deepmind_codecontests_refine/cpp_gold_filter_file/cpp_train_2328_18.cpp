#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 7;
long long n, m, v;
vector<long long> adj[maxn];
long long clique(long long n) { return n * (n - 1) / 2; }
long long maxe(long long n) {
  long long ans = 0;
  for (long long i = 1; i < n - 1; ++i) {
    ans = max(ans, n - 1 + clique(i) + clique(n - i - 1));
  }
  return ans;
}
long long done[maxn];
long long prllclique(vector<long long>& left, long long m) {
  for (long long i = 0; m && i < left.size(); ++i) {
    for (long long j = i + 1; m && j < left.size(); ++j) {
      cout << left[i] << " " << left[j] << "\n";
      --m;
    }
  }
  return m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> v;
  if (m < n - 1 || m > maxe(n)) {
    cout << -1;
    exit(0);
  }
  long long top = -1;
  for (long long i = 1; i < n - 1; ++i) {
    if (clique(i) + clique(n - i - 1) + n - 1 >= m) {
      top = i;
      break;
    }
  }
  vector<long long> left, right;
  int i = 1;
  while (top) {
    if (i != v) {
      left.push_back(i);
      --top;
      done[i] = 1;
    }
    ++i;
  }
  for (long long i = 0; i < left.size(); ++i) {
    cout << v << " " << left[i] << "\n";
  }
  for (long long i = 1; i <= n; ++i) {
    if (!done[i] && i - v) right.push_back(i);
  }
  for (long long i = 0; i < right.size(); ++i) {
    cout << v << " " << right[i] << "\n";
  }
  m -= n - 1;
  m = prllclique(left, m);
  prllclique(right, m);
  return 0;
}

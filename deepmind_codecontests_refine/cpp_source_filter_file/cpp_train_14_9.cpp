#include <bits/stdc++.h>
using namespace std;
const long long inf = LONG_MAX;
const long long arr = 1000000;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
}
vector<vector<long long> > g(arr);
int main(void) {
  long long n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    long long l, r;
    cin >> l >> r;
    g[l].push_back(r);
    g[r].push_back(l);
  }
  for (long long i = 2; i <= n; i++) {
    if (g[i].size() == 2) return cout << "NO" << '\n', 0;
  }
  cout << "YES" << '\n';
  return 0;
}

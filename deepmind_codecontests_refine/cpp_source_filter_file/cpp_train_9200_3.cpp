#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n), pre(100002);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<pair<pair<long long, long long>, long long>> op;
  long long p, q, r;
  for (int i = 0; i < m; i++) {
    cin >> p >> q >> r;
    op.push_back({{p, q}, r});
  }
  vector<long long> pr(m + 1);
  for (int i = 0; i < k; i++) {
    cin >> p >> q;
    p--;
    q--;
    pr[p]++;
    pr[q + 1]--;
  }
  for (int i = 1; i < m; i++) pr[i] = pr[i - 1] + pr[i];
  for (int i = 0; i < m; i++) {
    p = op[i].first.first;
    q = op[i].first.second;
    r = op[i].second;
    pre[p] += pr[i] * r;
    pre[q + 1] -= pr[i] * r;
  }
  for (int i = 2; i < 100000; i++) pre[i] = pre[i - 1] + pre[i];
  for (int i = 0; i < n; i++) cout << a[i] + pre[i + 1] << " ";
  cout << endl;
}

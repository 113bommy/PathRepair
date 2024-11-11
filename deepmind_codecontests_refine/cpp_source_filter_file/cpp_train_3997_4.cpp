#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<pair<int, int>, int>> op;
long long reputation[100005]{0};
long long a[100000]{0};
long long ans[100005]{0};
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int l, r, d;
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> d;
    op.push_back({{l, r}, d});
  }
  int f, t;
  for (int i = 0; i < k; i++) {
    cin >> f >> t;
    reputation[f - 1]++;
    reputation[t]--;
  }
  for (int i = 1; i < n; i++) reputation[i] += reputation[i - 1];
  for (int i = 0; i < n; i++) {
    int from = op[i].first.first;
    int to = op[i].first.second;
    long long d = (long long)op[i].second;
    ans[from - 1] += (long long)(d * reputation[i]);
    ans[to] -= (long long)(d * reputation[i]);
  }
  for (int i = 1; i < n; i++) ans[i] += ans[i - 1];
  for (int i = 0; i < n; i++) cout << (long long)a[i] + ans[i] << " ";
  cout << endl;
  return 0;
}

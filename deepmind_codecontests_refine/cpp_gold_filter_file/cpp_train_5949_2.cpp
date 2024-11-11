#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long m, n, i, j, k, x, y, z;
  cin >> n >> m >> k;
  long long a[n];
  vector<pair<long long, long long> > v;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end());
  bool pos[200000] = {false};
  long long sum = 0;
  for (i = n - 1; i > n - 1 - m * k; i--) {
    x = v[i].second;
    pos[x] = true;
    sum += v[i].first;
  }
  vector<long long> b;
  long long cur = 0;
  for (i = 0; i < n; i++) {
    if (cur == m) {
      cur = 0;
      b.push_back(i);
    }
    if (pos[i] == true) {
      cur++;
    }
  }
  cout << sum << endl;
  for (i = 0; i < k - 1; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}

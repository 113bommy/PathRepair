#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, inf = 1e9;
int n, m, k, a[N + 5];
bool good[N + 5];
int main() {
  vector<pair<int, int> > v;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(make_pair(a[i], i));
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long long ans = 0;
  for (int i = 0; i < m * k; i++) {
    ans += v[i].first;
    good[v[i].second] = true;
  }
  cout << ans << endl;
  int i = 0, cur = 0;
  while (--k) {
    cur = 0;
    while (cur < m) {
      cur += good[i];
      i++;
    }
    cout << i - 1 << " ";
  }
  cout << endl;
  return 0;
}

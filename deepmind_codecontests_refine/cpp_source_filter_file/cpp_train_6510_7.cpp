#include <bits/stdc++.h>
using namespace std;
int n, m;
map<long long, long long> hi;
long long res = 0;
long long a[1000000], b[1000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    hi[t]++;
  }
  cin >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  pair<long long, long long> hii = make_pair(0, 0);
  for (int i = 0; i < m; ++i) {
    if (hii < make_pair(hi[a[i]], hi[b[i]])) {
      hii = make_pair(hi[a[i]], hi[b[i]]);
      res = i;
    }
  }
  cout << res + 1;
  return 0;
}

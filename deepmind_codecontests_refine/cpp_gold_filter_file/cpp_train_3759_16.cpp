#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005];
map<long long, int> mm;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, y;
  cin >> n >> y;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m >> y;
  for (int i = 0; i < m; i++) cin >> b[i];
  int res = 2;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < n; j++) mm[(a[j] + (1 << i)) % (1 << (i + 1))]++;
    for (int j = 0; j < m; j++) mm[b[j] % (1 << (i + 1))]++;
    for (auto yy : mm) res = max(res, yy.second);
    mm.clear();
  }
  cout << (res) << '\n';
  return 0;
}

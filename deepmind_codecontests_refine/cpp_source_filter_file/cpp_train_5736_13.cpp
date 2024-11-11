#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int sum = 0;
  vector<int> a(n);
  map<int, int> c;
  c[0] = 1;
  bool fl = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > m) sum++;
    if (a[i] < m) sum--;
    if (a[i] == m) fl = 1;
    if (fl)
      ans += c[sum] + c[sum - 1];
    else
      c[sum]++;
  }
  cout << ans << endl;
  return 0;
}

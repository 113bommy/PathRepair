#include <bits/stdc++.h>
const int inf = (1e9 + 3);
const int M97 = ((int)1e9 + 7);
using namespace std;
pair<int, int> sol(long long int a, long long int b, int n) {
  int mx = 1e6 + 1;
  long long int i, j;
  for (i = 0; i < mx; i++) {
    j = (n - i * a) / b;
    if (j < 0) break;
    if ((i * a + j * b) == n) break;
  }
  if (i == mx || j < 0) return make_pair(-1, -1);
  return make_pair(i, j);
}
long long int i, j, k, l;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a == 1 || b == 1) {
    for (i = 1; i < n + 1; i++) cout << i << ' ';
    cout << "\n";
    return;
  }
  pair<int, int> z = sol(a, b, n);
  if (z == make_pair(-1, -1)) {
    cout << -1 << "\n";
    return;
  }
  vector<int> ans;
  i = 0;
  while (z.first--) {
    j = ++i;
    for (k = 0; k < a - 1; k++) ans.push_back(++i);
    ans.push_back(j);
  }
  while (z.second--) {
    j = ++i;
    for (k = 0; k < b - 1; k++) ans.push_back(++i);
    ans.push_back(j);
  }
  for (int zzz = 0; zzz < (int)ans.size(); zzz++) {
    cout << ans[zzz] << ' ';
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}

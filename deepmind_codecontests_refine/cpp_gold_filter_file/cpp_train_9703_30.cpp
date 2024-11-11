#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
int main() {
  if (!true) ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 2;
  while (ans * (ans + 1) / 2 <= n) ans++;
  vector<vector<int>> v(ans);
  int at = 1;
  for (int i = 0; i < ans; i++)
    for (int j = i + 1; j < ans; j++) v[i].push_back(at), v[j].push_back(at++);
  cout << ans << '\n';
  for (auto u : v) {
    for (auto x : u) cout << x << " ";
    cout << '\n';
  }
  exit(0);
}

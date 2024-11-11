#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int inf = 2e9 + 5;
double PI = 3.14159265358979323846;
void solve() {
  int n;
  cin >> n;
  int a[n];
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  int now = -1;
  int ans = 0;
  for (auto &x : m) {
    if (x.second > 1) {
      int next = x.second / 2;
      x.second = x.second % 2;
      m[x.first + 1] = next;
    }
    ans += (x.first - now - 1);
    if (x.second % 2 == 0) ans++;
    now = x.first;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}

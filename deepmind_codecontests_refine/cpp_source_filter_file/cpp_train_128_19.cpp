#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
inline void solve() {
  int n, m, temp;
  cin >> n >> m;
  vector<long long> inp1(1001, -1), inp2(1001, -1);
  for (int i = 0; i < n; i++) cin >> temp, inp1[temp]++;
  for (int i = 0; i < m; i++) cin >> temp, inp2[temp]++;
  int ans, num = 0;
  for (int i = 0; i < 1001; i++) {
    if (inp1[i] != -1 && inp2[i] != -1) {
      num++, ans = i;
    }
  }
  if (num)
    cout << "YES\n" << num << ' ' << ans << "\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

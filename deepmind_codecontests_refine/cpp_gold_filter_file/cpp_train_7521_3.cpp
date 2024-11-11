#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[110];
  string ans;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= 100; i++) ans += 'a' + i % 26;
  int last = 0;
  for (int i = 1; i <= n + 1; i++) {
    for (int i = last; i <= 100; i++)
      ans[i] == 'z' ? ans[i] = 'a' : ans[i] += 1;
    cout << ans << endl;
    last = a[i];
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

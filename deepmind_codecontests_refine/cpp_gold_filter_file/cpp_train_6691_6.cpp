#include <bits/stdc++.h>
using namespace std;
int dir[] = {0, 1, 0, -1, 1, 0, -1, 0};
struct actions {
  int i, j, x;
};
void solve() {
  long long int n, sum = 0;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % n) {
    cout << -1 << endl;
    return;
  }
  vector<actions> ans;
  for (int i = 2; i <= n; i++) {
    actions act;
    act.i = 1, act.j = i, act.x = i - (a[i] % i);
    ans.emplace_back(act);
    if (a[i] % i == 0) ans.pop_back();
    act.i = i, act.j = 1, act.x = a[i] / i;
    act.x += (a[i] % i) ? 1 : 0;
    ans.emplace_back(act);
  }
  long long int div = sum / n;
  for (int i = 2; i <= n; i++) {
    actions act;
    act.i = 1, act.j = i, act.x = div;
    ans.emplace_back(act);
  }
  cout << ans.size() << endl;
  for (auto s : ans) cout << s.i << " " << s.j << " " << s.x << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  for (int cn = 1; cn <= t; cn++) {
    solve();
  }
  return 0;
}

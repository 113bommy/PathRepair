#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[502], y[502];
vector<int> s[200001];
int pos[200001];
int ans[502];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < (int)(n); ++i) cin >> x[i] >> y[i];
  x[n] = x[0], y[n] = y[0];
  x[n + 1] = x[1], y[n + 1] = y[1];
  for (int i = 0; i < (int)(m); ++i) {
    int tmp;
    cin >> tmp;
    s[tmp].push_back(i + 1);
  }
  for (int i = 0; i < (int)(n); ++i) ans[i] = -1;
  bool flag = true;
  for (int i = 0; i < (int)(200000); ++i) pos[i] = 0;
  for (int i = 1; i < n; i += 2) {
    int len = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) +
              abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    if (len > 200000 || pos[len] == (int)s[len].size()) {
      flag = false;
      break;
    }
    ans[i] = s[len][pos[len]++];
  }
  if (flag) {
    cout << "YES\n";
    for (int i = 0; i < (int)(n); ++i) cout << ans[i] << ' ';
    cout << "\n";
    return 0;
  }
  for (int i = 0; i < (int)(n + 1); ++i) ans[i] = -1;
  flag = true;
  for (int i = 0; i < (int)(200000); ++i) pos[i] = 0;
  for (int i = 2; i <= n; i += 2) {
    int len = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) +
              abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    if (len > 200000 || pos[len] == (int)s[len].size()) {
      flag = false;
      break;
    }
    ans[i] = s[len][pos[len]++];
  }
  if (flag) {
    ans[0] = ans[n];
    cout << "YES\n";
    for (int i = 0; i < (int)(n); ++i) cout << ans[i] << ' ';
    cout << "\n";
    return 0;
  }
  cout << "NO\n";
  return 0;
}

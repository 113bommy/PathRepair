#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    int x1;
    cin >> x1;
    if (x1 < 0)
      a.push_back(abs(x1));
    else if (x1 > 0)
      b.push_back(x1);
  }
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  long long int ans = 0;
  for (int i = 0; i < a.size(); i = i + k) {
    ans = ans + 2 * abs(a[i]);
  }
  for (int i = 0; i < b.size(); i = i + k) {
    ans = ans + 2 * b[i];
  }
  int x4, x5;
  if (!a.empty())
    x4 = a[0];
  else
    x4 = 0;
  if (!b.empty())
    x5 = b[0];
  else
    x5 = 0;
  cout << ans - max(x4, x5) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

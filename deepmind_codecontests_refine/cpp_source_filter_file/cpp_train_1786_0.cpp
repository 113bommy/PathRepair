#include <bits/stdc++.h>
using namespace std;
int oo = 1000000000;
int n, k;
pair<int, int> a[100005];
int f(int idx1, int idx2) { return (a[idx2].second < a[idx1].first); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) a[i].first = oo;
  for (int i = 1; i <= k; i++) {
    int idx;
    cin >> idx;
    a[idx].first = min(a[i].first, i);
    a[idx].second = max(a[i].second, i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].first == oo) ans++;
    if (i - 1 != 0) ans += f(i, i - 1);
    if (i + 1 != n + 1) ans += f(i, i + 1);
  }
  cout << ans << endl;
  return 0;
}

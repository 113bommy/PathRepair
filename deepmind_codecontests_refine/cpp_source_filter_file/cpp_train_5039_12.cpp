#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  vector<int> best(n + 1);
  best[n] = 0;
  int cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    cur -= 2 * a[i];
    best[i] = max(best[i + 1], cur);
  }
  int ans = 0;
  cur = 0;
  for (int i = 1; i <= n; ++i) {
    cur -= 2 * a[i - 1];
    ans = max(ans, cur + best[i]);
  }
  cout << ans + sum << endl;
  return 0;
}

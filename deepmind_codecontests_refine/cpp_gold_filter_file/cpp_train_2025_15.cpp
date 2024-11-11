#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int n, p, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    if (a[i] < a[i - 1]) {
      ans = n - i;
      p++;
    }
  }
  if (a[0] < a[n - 1]) {
    p++;
    ans = 0;
  }
  if (p > 1)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}

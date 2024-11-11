#include <bits/stdc++.h>
const int N = 1e5 + 5;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, l[N], r[N];
  cin >> n;
  int ans = n;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  sort(l, l + n);
  sort(r, r + n);
  for (int i = 0; i < n; i++) {
    ans += max(l[i], r[i]);
  }
  cout << ans << endl;
  return 0;
}

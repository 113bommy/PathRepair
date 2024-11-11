#include <bits/stdc++.h>
using namespace std;
int l[100005];
int r[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  sort(l + 1, l + 1 + n);
  sort(r + 1, r + 1 + n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (max(l[i], r[i]) + 1);
  }
  cout << ans << endl;
  return 0;
}

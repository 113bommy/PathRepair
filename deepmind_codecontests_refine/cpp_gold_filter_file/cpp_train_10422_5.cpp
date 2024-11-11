#include <bits/stdc++.h>
using namespace std;
int n, l[100005], r[100005];
long long ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> l[i] >> r[i];
  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);
  ans = n;
  for (int i = (1); i <= (n); ++i) ans += max(l[i], r[i]);
  cout << ans;
}

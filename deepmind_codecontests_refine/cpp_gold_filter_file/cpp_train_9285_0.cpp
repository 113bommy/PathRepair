#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];
void sol() {
  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
  sort(a, a + n);
  long long horizon = 0, vertical = 0;
  for (int i = 0; i < n / 2; i++) {
    horizon += a[i];
  }
  vertical = sum - horizon;
  long long ans = (vertical * vertical) + (horizon * horizon);
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc = 1;
  while (tc--) {
    sol();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void hehe() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> arr(n);
  long long int ans = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i % 2 == 0) {
      ans = min(ans, 1ll * arr[i]);
    }
  }
  if (n % 2 == 0) {
    ans = 0;
  } else {
    ans = min(ans, 1ll * k / (m / ((n + 1) / 2)));
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    hehe();
  }
  return 0;
}

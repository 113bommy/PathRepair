#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int inp[100100], res[100100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> inp[i];
  int prev = 0;
  for (int i = n - 1; i >= 0; i--) {
    prev--;
    prev -= inp[i];
    prev = max(prev, 0);
    res[i] = prev;
    prev = res[i] + inp[i];
  }
  prev = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    prev -= inp[i];
    prev--;
    prev = max(prev, 0);
    res[i] = max(res[i], prev);
    ans += res[i];
    prev = res[i] + inp[i] + 1;
  }
  cout << ans << '\n';
  return 0;
}

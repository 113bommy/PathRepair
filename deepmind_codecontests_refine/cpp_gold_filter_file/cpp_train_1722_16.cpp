#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 1e5 + 5, oo = 0x3f3f3f3f, mod = 1e9 + 7;
int n, k, a[N], b[N];
bool can_bake(int cake) {
  int powder = k;
  for (int i = 0; i < n; i++) {
    int need = a[i] * cake;
    if (b[i] < need) {
      if (powder + b[i] < need) {
        return 0;
      }
      powder -= (need - b[i]);
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int ans = 0;
  for (int i = 0; i < 2004; i++) {
    if (!can_bake(i)) {
      ans = i - 1;
      break;
    }
  }
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXH = 212345;
int h[MAXH];
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int hi;
    cin >> hi;
    h[hi]++;
  }
  for (int k = MAXH - 2; k >= 0; k--) {
    h[k] += h[k + 1];
  }
  int ans = 0;
  int p = MAXH - 1;
  while (h[p] < n) {
    int sum = h[p];
    p--;
    while (h[p] < n and sum + h[p] < k) {
      sum += h[p];
      p--;
    }
    if (sum) ans++;
  }
  cout << ans << endl;
}

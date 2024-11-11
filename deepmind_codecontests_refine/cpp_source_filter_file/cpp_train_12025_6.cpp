#include <bits/stdc++.h>
using namespace std;
void task() {
  int n, ans = 0, count, mid;
  cin >> n;
  vector<int> needs(n);
  vector<int> price(n);
  for (int K = 0; K < n; K++) cin >> needs[K] >> price[K];
  for (int K = 0; K < n; K++) {
    mid = K;
    ans += (needs[K] * price[K]);
    count = 0;
    for (int L = K + 1; L < n; L++) {
      if (price[L] < price[L - 1]) {
        K = L - 1;
        break;
      }
      if (L == n - 1) K = L;
      count += needs[L];
    }
    ans += (price[mid] * count);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  task();
  return 0;
}

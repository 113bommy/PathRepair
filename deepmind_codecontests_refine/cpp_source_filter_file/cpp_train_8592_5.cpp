#include <bits/stdc++.h>
using namespace std;
int t;
int n, r;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> r;
    int sum = 0;
    for (int i = 1; i < n; i++) {
      int a;
      cin >> a;
      sum += a;
    }
    int q = (sum / n + 1) * n;
    q += (r - 1);
    if (q > sum + 3) q -= n;
    cout << q - sum << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] >= k) {
      cnt++;
    }
  }
  cout << cnt / 3;
  return 0;
}

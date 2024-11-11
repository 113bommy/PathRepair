#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, vol, sum = 0, mx = INT_MIN;
  cin >> n >> vol;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mx = max(mx, v[i]);
    sum += v[i];
  }
  if (sum - 2 * mx <= vol) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

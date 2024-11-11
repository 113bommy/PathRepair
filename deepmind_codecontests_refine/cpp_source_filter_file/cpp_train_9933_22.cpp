#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> h[i + 1];
    h[i + 1] += h[i];
  }
  int ans = 0;
  for (int i = 0; i + k <= n; ++i) {
    if (h[ans + k] - h[ans] > h[i + k] - h[k]) {
      ans = i;
    }
  }
  cout << ans + 1 << endl;
}

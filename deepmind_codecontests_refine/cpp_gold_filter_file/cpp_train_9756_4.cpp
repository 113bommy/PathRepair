#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  map<int, int> max_rev;
  for (int i = 0; i < 2; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> a >> b;
      max_rev[a] = max(max_rev[a], b);
    }
  }
  long long ans = 0;
  for (auto p : max_rev) {
    ans = ans + p.second;
  }
  cout << ans;
  return 0;
}

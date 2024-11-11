#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, a, b;
  cin >> n >> a >> b;
  long long h[n];
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  sort(h + 1, h + n + 1);
  int ans = 0;
  if (h[b + 1] > h[b]) {
    ans = h[b + 1] - h[b];
  }
  return ans;
}
int main() {
  cout << solve() << endl;
  return 0;
}

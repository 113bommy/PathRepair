#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  int h[n];
  vector<int> v;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    int rem = h[i] % (a + b);
    if (rem <= a && rem != 0)
      ans++;
    else if (rem == 0)
      v.push_back((b - 1) / 2 + 1);
    else
      v.push_back((rem - a - 1) / 2 + 1);
  }
  sort(v.begin(), v.end());
  for (auto x : v) {
    k -= x;
    if (k < 0) break;
    ans++;
  }
  cout << ans << endl;
}

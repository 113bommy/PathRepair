#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 21) - 1;
int ans, n, mx1[N + 10], mx2[N + 10], a[N + 10];
vector<int> mx;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx2[N - a[i]] = mx1[N - a[i]];
    mx1[N - a[i]] = i;
  }
  for (int j = 0; j <= 21; j++) {
    for (int i = 0; i <= N; i++) {
      if (i & (1 << j)) {
        int x = i ^ (1 << j);
        mx.clear();
        mx.push_back(mx1[x]);
        mx.push_back(mx2[x]);
        mx.push_back(mx1[i]);
        mx.push_back(mx2[i]);
        sort(mx.begin(), mx.end());
        reverse(mx.begin(), mx.end());
        mx1[i] = mx[0];
        mx2[i] = mx[1];
      }
    }
  }
  for (int i = 1; i <= n - 2; i++) {
    int best = 0;
    int mask = N - a[i];
    for (int j = 21; j >= 0; j--) {
      if (!(mask & (1 << j))) continue;
      int best1 = best + (1 << j);
      if (mx2[N - best1] > i) best = best1;
    }
    ans = max(ans, a[i] + best);
  }
  cout << ans;
  return 0;
}

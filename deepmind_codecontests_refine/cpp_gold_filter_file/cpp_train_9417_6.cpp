#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897;
const long long mod = 1e9 + 7;
const int M = 1000005;
const long long INF = 1e9 + 5;
int mv[2 * M];
int solve() {
  int n;
  cin >> n;
  set<int> second;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    second.insert(x);
  }
  vector<int> a;
  for (auto it : second) a.push_back(it);
  n = int((a).size());
  int M = 2 * a.back();
  int l = 0, i = 0, j = 1;
  while (j <= M) {
    if (j < a[i] || i == n)
      mv[j++] = l;
    else
      l = a[i++];
  }
  int ans = 0;
  for (int j = 0; j < int((a).size()); j++) {
    int x = 2 * a[j];
    while (x <= M) {
      ans = max(ans, mv[x - 1] % a[j]);
      x += a[j];
    }
  }
  cout << ans << "\n";
  return 0;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int t = 1, i = 1;
  while (t--) {
    solve();
  }
  return 0;
}

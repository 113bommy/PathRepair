#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> pos;
  for (int &x : a) cin >> x;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    pos[num] = i;
  }
  int ans = 0;
  int maxi = -1;
  for (int i = 0; i < n; i++) {
    if (pos[a[i]] < maxi)
      ans++;
    else
      maxi = pos[a[i]];
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}

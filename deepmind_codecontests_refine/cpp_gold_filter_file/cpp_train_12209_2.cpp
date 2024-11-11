#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, T;
  cin >> n >> T;
  unordered_map<long long, long long> mp, ans, vis;
  vector<long long> ar(n), b;
  for (long long i = 0; i < n; i++) {
    cin >> ar[i];
    mp[ar[i]]++;
  }
  for (long long i = 0; i < n; i++) {
    if (T == 2 * ar[i])
      b.push_back(ar[i]);
    else if (mp[ar[i]] > 0 && mp[T - ar[i]] > 0) {
      if (vis[T - ar[i]] == 0) {
        ans[T - ar[i]] = 1;
        vis[T - ar[i]] = 1;
      }
      mp[ar[i]] = 0;
      mp[T - ar[i]] = 0;
    }
  }
  long long s = (int)b.size() / 2;
  for (long long i = 0; i < n; i++) {
    if (ar[i] * 2 == T) {
      if (s > 0) {
        cout << "1 ";
        s--;
      } else
        cout << "0 ";
    } else
      cout << ans[ar[i]] << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

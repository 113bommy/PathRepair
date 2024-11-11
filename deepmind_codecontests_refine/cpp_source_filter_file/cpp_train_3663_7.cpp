#include <bits/stdc++.h>
using namespace std;
long long int modpwr(long long int x, long long int y, long long int m) {
  x %= m;
  if (x == 0) return 0;
  long long int ans = 1;
  while (y) {
    if (y % 2) {
      ans = (ans * x) % m;
    }
    x = (x * x) % m;
    y = y / 2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    long long int ans = 0;
    vector<pair<long long int, long long int>> v(n);
    for (int i = 0; i < n; i++) {
      long long int a;
      cin >> a;
      v.push_back(make_pair(a, i + 1));
    }
    sort(v.begin(), v.end());
    long long int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      ans += (v[i].first * cnt + 1);
      cnt++;
    }
    cout << ans << "\n";
    for (int i = n - 1; i >= 0; i--) {
      cout << v[i].second << " ";
    }
  }
}

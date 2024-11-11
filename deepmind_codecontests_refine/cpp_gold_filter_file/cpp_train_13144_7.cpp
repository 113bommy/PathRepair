#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string st;
    cin >> st;
    vector<long long> v(n);
    map<long long, long long> m;
    for (int i = 0; i < n; i++) {
      v[i] = (st[i] - '0') - 1;
    }
    long long cu = 0, ans = 0;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
      cu += v[i];
      ans += m[cu];
      m[cu]++;
    }
    cout << ans << "\n";
  }
}

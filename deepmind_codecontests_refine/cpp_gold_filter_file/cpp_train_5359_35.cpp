#include <bits/stdc++.h>
using namespace std;
long long int n, m;
void solve() {
  long long int t, k, z, p, q, u, v, x, y, ct = 0, flag = 0;
  cin >> n >> m;
  cin >> t;
  unordered_map<long long int, long long int> boy;
  unordered_map<long long int, long long int> girl;
  while (t--) {
    cin >> x;
    boy[x] = 1;
  }
  cin >> t;
  while (t--) {
    cin >> x;
    girl[x] = 1;
  }
  ct = 0;
  long long int boySize = boy.size();
  long long int girlSize = girl.size();
  while (true) {
    x = ct % n;
    y = ct % m;
    if (boy.find(x) != boy.end()) {
      girl[y] = 1;
    }
    if (girl.find(y) != girl.end()) {
      boy[x] = 1;
    }
    if (boy.size() == n && girl.size() == m) {
      cout << "Yes\n";
      break;
    }
    boySize = boy.size();
    girlSize = girl.size();
    ct++;
    if (ct > n * m + max(n, m)) {
      cout << "No\n";
      break;
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  solve();
}

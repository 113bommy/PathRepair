#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long mod = 1e9 + 7;
map<int, int> a, b;
vector<int> mp[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x, y;
      cin >> x >> y;
      a[x]++;
      b[y]++;
      mp[x].push_back(y);
    }
    long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) {
      long long sum = 0;
      for (int j = 0; j < mp[i].size(); j++) {
        sum += b[mp[i][j]] - 1;
      }
      ans -= 1ll * (a[i] - 1) * sum;
    }
    for (int i = 1; i <= n; i++) {
      a[i] = b[i] = 0;
      mp[i].clear();
    }
    cout << ans << endl;
  }
}

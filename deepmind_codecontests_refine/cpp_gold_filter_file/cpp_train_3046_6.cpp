#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    map<int, int> cnt;
    int maxi = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] % k == 0) continue;
      cnt[k - (v[i] % k)]++;
      maxi = max(maxi, cnt[k - (v[i] % k)]);
    }
    long long int vys = 0;
    for (auto [key, value] : cnt) {
      if (value == maxi) {
        vys = k * 1ll * (value - 1) + key + 1;
      }
    }
    cout << vys << endl;
  }
  return 0;
}

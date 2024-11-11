#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, d;
    cin >> n >> k >> d;
    int a[n];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int check_ele = 0;
    int count = 0, ans = 0, ans_final = 10000, o = 0;
    map<int, int> mp;
    for (int i = 0; i <= n - d; i++) {
      for (int j = i + 1; j <= i + d; j++) {
        mp[a[j]]++;
        count++;
        while (count == d) {
          for (auto x : mp) {
            if (x.second >= 1) {
              ans++;
            }
          }
          ans_final = min(ans_final, ans);
          for (int x = 1; x <= k; x++) mp[x] = 0;
          count = 0;
          ans = 0;
        }
      }
      o++;
    }
    cout << ans_final << endl;
  }
  return 0;
}

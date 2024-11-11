#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N] = {};
map<int, int> nums;
void io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main(int argc, char const *argv[]) {
  io();
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    nums.clear();
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      nums[a[i]]++;
    }
    long long res = 1;
    for (int i = 1; i <= 26; i++) {
      int l = 0, r = n - 1, cnt = 0;
      int vis[30] = {};
      res = max(res, 1ll * nums[i]);
      while (l < r) {
        while (a[l] != i && l < r) {
          vis[a[l]]++;
          l++;
        }
        if (l == r) break;
        while (a[r] != i && l < r) {
          vis[a[r]]++;
          r--;
        }
        if (l == r) break;
        cnt += 2;
        l++;
        r--;
        for (int j = 1; j <= 26; j++) {
          if (i == j) continue;
          res = max(res, 1ll * cnt + nums[j] - vis[j]);
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}

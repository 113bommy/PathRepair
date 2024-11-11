#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos[200];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      pos[a[i]].emplace_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 200; i++) {
      ans = max(ans, (int)pos[i].size());
      for (int j = 0; j < (int)pos[i].size() / 2; j++) {
        int low = pos[i][j];
        int high = pos[i][(int)pos[i].size() - j - 1];
        for (int k = 0; k < 200; k++) {
          if (i == k) continue;
          if (pos[k].empty() || pos[k][0] > high || pos[k].back() < low)
            continue;
          int l =
              upper_bound(pos[k].begin(), pos[k].end(), low) - pos[k].begin();
          int r = lower_bound(pos[k].begin(), pos[k].end(), high) -
                  pos[k].begin() - 1;
          ans = max(ans, r - l + 1 + 2 * (low + 1));
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

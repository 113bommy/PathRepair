#include <bits/stdc++.h>
using namespace std;
int n, x, y, ans;
vector<int> a[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int id = 0; id < n; id++) {
    ans = 0;
    cin >> x >> y;
    if (y == 0) {
      for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
          ans++;
          if (x / i != i) {
            ans++;
          }
        }
      }
    } else {
      for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
          if (a[i].empty()) {
            ans++;
          } else {
            int pos =
                lower_bound(a[i].begin(), a[i].end(), id - y) - a[i].begin();
            if (pos == a[i].size() ||
                !(a[i][pos] >= id - y && a[i][pos] <= id - 1)) {
              ans++;
            }
          }
          if (x / i != i) {
            if (a[i].empty()) {
              ans++;
            } else {
              int pos = lower_bound(a[x / i].begin(), a[x / i].end(), id - y) -
                        a[x / i].begin();
              if (pos == a[x / i].size() ||
                  !(a[x / i][pos] >= id - y && a[x / i][pos] <= id - 1)) {
                ans++;
              }
            }
          }
        }
      }
    }
    cout << ans << '\n';
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        a[i].push_back(id);
        if (x / i != i) {
          a[x / i].push_back(id);
        }
      }
    }
  }
  return 0;
}

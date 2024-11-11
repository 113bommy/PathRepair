#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, a[105];
  vector<int> v;
  cin >> n >> k >> x;
  a[0] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == a[i - 1] && (a[i] == x)) {
      v.push_back(i - 1);
    }
  }
  if (v.size() == 0) {
    cout << "0" << endl;
    return 0;
  }
  int Max = 2;
  for (int i = 0; i < v.size(); i++) {
    int it1 = v[i] - 1, it2 = v[i] + 2;
    int ans = 2;
    if (it1 < 1 || it2 > n) {
      continue;
    }
    if (a[it1] != a[it2]) {
      continue;
    } else if (a[it1] == a[it2]) {
      while (a[it1] == a[it2]) {
        if (it1 < 1 || it2 > n) break;
        int cnt = 2;
        while (a[it1] == a[it1 - 1] && it1 >= 2) {
          cnt++;
          --it1;
        }
        --it1;
        while (a[it2] == a[it2 + 1] && it2 <= n - 1) {
          cnt++;
          ++it2;
        }
        ++it2;
        if (cnt >= 3) {
          ans += cnt;
        } else if (cnt < 3)
          break;
      }
    }
    Max = max(ans, Max);
  }
  cout << Max << endl;
  return 0;
}

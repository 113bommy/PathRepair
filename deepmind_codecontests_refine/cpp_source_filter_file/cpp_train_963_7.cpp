#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int j = 0;
  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int k = 0;
    while (i < n && a[i] == j) {
      ++i;
      ++k;
    }
    if (cnt == 0) {
      if (k == 0) {
        ans += 2 * j;
        cnt += 2;
      } else if (k == 1) {
        ans += j;
        ++cnt;
      }
    } else if (cnt == 1) {
      if (k == 0) {
        ans += j;
        ++cnt;
      }
    }
    if (cnt == 2) {
      break;
    }
    ++j;
    --i;
  }
  if (cnt == 2) {
    cout << ans << endl;
  } else if (cnt == 1) {
    cout << ans + j << endl;
  } else {
    cout << j * 2;
  }
}
int main() {
  int n = 1;
  cin >> n;
  for (unsigned long long i = 0; i < n; ++i) {
    solve();
  }
  return 0;
}

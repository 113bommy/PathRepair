#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int p;
  int a[1000];
  std::vector<int> maxN(100000);
  std::vector<int> ans(100000);
  cin >> n;
  cin >> p;
  int t;
  for (int i = 1; i < n + 1; i++) {
    cin >> maxN[i];
  }
  for (int i = n; i > 0; i--) {
    int t = i;
    if (n - i > p) {
      ans[i] += 1 + p;
    } else {
      ans[i] += 1 + (n - i);
    }
    while (t > 0) {
      if (maxN[t] > 0) {
        if (t - maxN[t] > 2 * p) {
          ans[i] += 1 + 2 * p;
        } else {
          ans[i] += (t - maxN[t]);
        }
      } else {
        if (t > p) {
          ans[i] += p;
        } else {
          ans[i] += t - 1;
        }
      }
      t = maxN[t];
    }
  }
  for (int i = 1; i < n + 1; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}

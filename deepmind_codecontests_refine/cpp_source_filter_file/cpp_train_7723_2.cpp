#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n;
  cin >> k;
  while (k--) {
    cin >> n;
    vector<int> v;
    for (i = 1; i <= n; i++) {
      cin >> j;
      v.push_back(j);
    }
    sort(v.begin(), v.end());
    int a = v[n - 1], res = 0;
    for (int mn = a;; mn--) {
      if (v[a - mn] >= mn) {
        res = mn;
        break;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}

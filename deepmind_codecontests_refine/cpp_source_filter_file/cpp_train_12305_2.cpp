#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t n;
    cin >> n;
    int64_t x = n;
    vector<int> a;
    while (x) {
      int rem = x % 3;
      a.push_back(rem);
      x /= 3;
    }
    a.push_back(0);
    int ind = -1;
    int i = a.size();
    for (int k = i - 1; k >= 0; k--) {
      if (a[k] == 2) {
        ind = k;
        break;
      }
    }
    if (ind == -1) {
      cout << n << "\n";
      continue;
    }
    int index = -1;
    for (int k = i - 1; k > ind; k--) {
      if (a[k] == 0) {
        index = k;
        break;
      }
    }
    a[index] = 1;
    for (int k = index - 1; k >= 0; k--) a[k] = 0;
    int64_t p = 1;
    int64_t num = 0;
    for (int k = 0; k < i; k++) {
      num += a[k] * p;
      p *= 3;
    }
    cout << num << "\n";
  }
  return 0;
}

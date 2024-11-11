#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w;
  cin >> n >> w;
  int l = 0;
  int r = w;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    cur += t;
    if (cur < 0) {
      l = max(l, abs(cur));
    }
    if (cur + r > w) {
      r = min(r, r - ((cur + r) - w));
    }
  }
  cout << max(0, r - l + 1);
}

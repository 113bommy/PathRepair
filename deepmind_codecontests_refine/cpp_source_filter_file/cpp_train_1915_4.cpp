#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  int pos = 0, neg = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      pos += 1;
    } else {
      neg += 1;
    }
  }
  int l, r;
  while (m--) {
    cin >> l >> r;
    if ((r - l) % 2 == 0 || (r - l) == 0)
      cout << 0 << endl;
    else {
      int mini = (r - l) / 2;
      if (pos < mini || neg < mini) {
        cout << 0 << endl;
      } else {
        cout << 1 << endl;
      }
    }
  }
  return 0;
}

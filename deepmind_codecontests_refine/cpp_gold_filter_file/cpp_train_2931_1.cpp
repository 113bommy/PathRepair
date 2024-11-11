#include <bits/stdc++.h>
using namespace std;
int zapros(int x, int l, int r) {
  cout << "1 " << r - l << ' ' << x + 1 << ' ';
  for (int i = l; i < r; i++) {
    cout << i + 1 << ' ';
  }
  cout << endl;
  int ret;
  cin >> ret;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  cin >> ttt;
  while (ttt--) {
    int n;
    cin >> n;
    int diat = zapros(0, 1, n);
    int l = 1;
    int r = n;
    while (r - l > 1) {
      int mid = (r + l) / 2;
      int diat2 = zapros(0, l, mid);
      if (diat2 == diat)
        r = mid;
      else
        l = mid;
    }
    cout << 1 << ' ' << n - 1 << ' ' << l + 1 << ' ';
    for (int i = 0; i < n; i++) {
      if (i != l) cout << i + 1 << ' ';
    }
    cout << endl;
    int ret;
    cin >> ret;
    cout << -1 << ' ' << ret << endl;
  }
  return 0;
}

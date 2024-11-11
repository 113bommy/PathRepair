#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(int argc, char const *argv[]) {
  int n, h, midx = 0, mi = 100000000;
  cin >> n >> h;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (mi > a[i]) {
      a[i] = mi;
      midx = i;
    }
  }
  if (n == 2) {
    cout << 0 << endl;
    cout << "2 2";
    return 0;
  }
  sort(a, a + n);
  int mn = min(a[0] + a[1] + h, a[1] + a[2]);
  int mx = max(a[0] + a[n - 1] + h, a[n - 1] + a[n - 2]);
  int d1 = mx - mn;
  int d2 = a[n - 1] + a[n - 2] - (a[0] + a[1]);
  if (d1 <= d2) {
    cout << d1 << endl;
    for (int i = 0; i < n; ++i) {
      if (i == midx)
        cout << 1 << " ";
      else
        cout << 2 << " ";
    }
  } else {
    cout << d2 << endl;
    for (int i = 0; i < n; ++i) {
      cout << 2 << " ";
    }
  }
  return 0;
}

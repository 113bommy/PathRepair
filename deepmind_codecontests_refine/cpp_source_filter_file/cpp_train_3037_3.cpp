#include <bits/stdc++.h>
using namespace std;
int a[100005], n;
int main() {
  int q;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = a[i] + a[i - 1];
  }
  cin >> q;
  int x, y, dif;
  for (int i = 1; i <= q; i++) {
    cin >> x >> y;
    dif = a[y] - a[x - 1];
    cout << dif / 10;
  }
  return 0;
}

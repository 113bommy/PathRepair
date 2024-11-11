#include <bits/stdc++.h>
using namespace std;
int n, x, y, a[100005];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x >> y;
  int cnt = x, cot = y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
  fv:;
    for (int j = i; j >= i - x && j >= 1; j--) {
      if (a[i] > a[j]) {
        i++;
        goto fv;
      }
    }
    for (int j = i; j <= i + y && j <= n; j++) {
      if (a[i] > a[j]) {
        i++;
        goto fv;
      }
    }
    cout << i << endl;
    break;
  }
  return 0;
}

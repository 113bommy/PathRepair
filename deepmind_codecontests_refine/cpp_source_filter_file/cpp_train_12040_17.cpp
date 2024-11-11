#include <bits/stdc++.h>
using namespace std;
int arr[int(1e6) + 5][9] = {0};
int f(int x);
int CalcHash(int x) {
  if (x < 10) {
    return x;
  }
  return f(x);
}
int f(int x) {
  int prod = 1;
  while (x != 0) {
    if (x % 10 != 0) {
      prod *= (x % 10);
    }
    x /= 10;
  }
  return CalcHash(prod);
}
void solve() {
  long long l, r, k;
  cin >> l >> r >> k;
  if (l > 1) {
    cout << arr[r - 1][k - 1] - arr[l - 2][k - 1] << endl;
  } else {
    if (k != 1)
      cout << arr[r - 1][k - 1] << endl;
    else
      cout << arr[r - 1][k - 1] + 1 << endl;
  }
}
int main(void) {
  cin.tie(0)->sync_with_stdio(0);
  int tc = 1;
  cin >> tc;
  arr[0][0] = 1;
  int index = -1;
  for (int i = 1; i <= int(1e6); i++) {
    for (int j = 0; j < 9; j++) {
      arr[i][j] = arr[i - 1][j];
    }
    index = CalcHash(i + 1);
    arr[i][index - 1]++;
  }
  while (tc--) solve();
  return 0;
}

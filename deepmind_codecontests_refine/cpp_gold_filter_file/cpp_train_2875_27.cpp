#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const long double EPS = 1e-12;
int n, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  if (n == k) {
    cout << 0 << " ";
    cout << 0;
    return 0;
  }
  if (k == 0) {
    cout << 0;
  } else {
    cout << 1;
  }
  cout << " ";
  int ans = 0;
  if (n % 3 == 0) {
    ans = n - (n / 3);
  } else {
    ans = n - (n / 3 + 1);
  }
  int dif = n - ans;
  if (dif == k) {
    cout << ans;
  } else {
    if (dif < k) {
      cout << ans - (k - dif);
    } else {
      cout << k * 2;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const char E = '\n';
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  long long a[100010] = {0};
  a[0] = 0;
  long long sum = 0;
  int k0 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] == 0) k0++;
  }
  if (k0 == 0) {
    cout << "cslnb" << E;
    return 0;
  }
  if (sum == 0) {
    cout << "cslnb" << E;
    return 0;
  }
  sort(a + 1, a + n + 1);
  int kl = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      kl++;
    }
  }
  if (kl >= 2) {
    cout << "cslnb" << E;
    return 0;
  }
  for (int i = 2; i < n; i++) {
    if (a[i] == a[i - 1] + 1 && a[i] == a[i + 1]) {
      cout << "cslnb" << E;
      return 0;
    }
  }
  if (n == 1) {
    if (a[1] % 2 == 0) {
      cout << "cslnb" << E;
    } else {
      cout << "sjfnb" << E;
    }
    return 0;
  }
  long long km = 0;
  for (int i = 1; i <= n; i++) {
    km += a[i] - (i - 1);
  }
  if (km % 2 == 0) {
    cout << "cslnb" << E;
  } else if (km % 2 == 1) {
    cout << "sjfnb" << E;
  }
  return 0;
}

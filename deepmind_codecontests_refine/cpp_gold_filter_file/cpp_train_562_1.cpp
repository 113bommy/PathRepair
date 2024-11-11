#include <bits/stdc++.h>
using namespace std;
long long get(int j, long long b) {
  long long d1 = b / j + 1, d2 = b / j;
  return d1 * d1 * (b % j) + d2 * d2 * (j - b % j);
}
int main() {
  ios::sync_with_stdio(0);
  long long a, b;
  cin >> a >> b;
  if (a == 0) {
    cout << (-b * b) << "\n";
    for (int i = 0; i < b; i++) cout << "x";
    return 0;
  }
  if (b == 0) {
    cout << (a * a) << "\n";
    for (int i = 0; i < a; i++) cout << "o";
    return 0;
  }
  long long ans = a * a - b * b;
  int p = 1, q = 1;
  for (int i = 1; i <= a; i++) {
    for (int j = i - 1; j <= i + 1; j++) {
      if (j == 0 || j > b) continue;
      long long positive = (a - i + 1) * (a - i + 1) + i - 1;
      long long negative = get(j, b);
      if (positive - negative > ans) {
        ans = positive - negative;
        p = i;
        q = j;
      }
    }
  }
  cout << ans << "\n";
  long long res_w = p, res_l = q;
  if (res_w >= res_l) {
    for (int i = 0; i < res_w; i++) {
      int wl = (i > 0) ? 1 : a - (res_w - 1);
      for (int x = 0; x < wl; x++) cout << "o";
      int ll = (i < b % res_l) ? (b / res_l + 1) : (b / res_l);
      if (i < res_l)
        for (int x = 0; x < ll; x++) cout << "x";
    }
  } else {
    for (int i = 0; i < res_l; i++) {
      int ll = (i < b % res_l) ? (b / res_l + 1) : (b / res_l);
      for (int x = 0; x < ll; x++) cout << "x";
      int wl = (i > 0) ? 1 : a - (res_w - 1);
      if (i < res_w)
        for (int x = 0; x < wl; x++) cout << "o";
    }
  }
  return 0;
}

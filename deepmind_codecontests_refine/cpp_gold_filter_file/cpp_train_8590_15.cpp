#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, h;
  cin >> n >> d >> h;
  if (h * 2 < d) {
    cout << "-1";
    return 0;
  }
  if (d < h) {
    cout << "-1";
    return 0;
  }
  if (d == 1 && n > 2) {
    cout << "-1";
    return 0;
  }
  if (h == n - 1 && d != h) {
    cout << "-1";
    return 0;
  }
  int kol = 0;
  for (int i = 2; i <= h + 1; i++) {
    kol++;
    cout << i - 1 << " " << i << endl;
  }
  if (n == kol + 1)
    if (d == h) return 0;
  int k = h;
  if (d > k) {
    cout << "1 " << h + 2 << endl;
    k += 1;
    while (d > k) {
      k++;
      cout << k << " " << k + 1 << endl;
    }
  }
  k++;
  int t = k;
  if (h > 1)
    for (int i = 0; i < n - t; i++) {
      k++;
      cout << "2 " << k << endl;
    }
  else
    for (int i = 0; i < n - t; i++) {
      k++;
      cout << "1 " << k << endl;
    }
  return 0;
}

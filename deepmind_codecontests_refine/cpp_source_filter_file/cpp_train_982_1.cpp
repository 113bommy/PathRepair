#include <bits/stdc++.h>
using namespace std;
int n, k, d, a[1005][1005], ct = 1;
int main(int argc, const char* argv[]) {
  cin >> n >> k >> d;
  if ((k == 1 && n != 1) || (n == 3 && k == 2 && d == 1)) {
    cout << -1 << endl;
    return 0;
  } else if (n == 1) {
    for (int i = 0; i < d; i++) {
      cout << 1 << endl;
    }
    return 0;
  }
  int temp = 1;
  for (int i = 0; i < d; i++) {
    temp *= k;
    if (temp > n) {
      break;
    }
  }
  if (temp < n) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < d; i++) {
    int pnt = 0;
    for (int j = 0; j < n; j++) {
      int l;
      for (l = j; l < n && l - j < ct; l++) {
        cout << (pnt % k) + 1 << " ";
      }
      pnt++;
      j = l;
    }
    if (ct < 1005) {
      ct *= k;
    }
    cout << endl;
  }
  return 0;
}

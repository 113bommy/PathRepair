#include <bits/stdc++.h>
using namespace std;
int n, cnt1;
bool ok(int l, int r) {
  cout << "? ";
  for (int i = 0; i < l; i++) {
    putchar('0');
  }
  for (int i = l; i <= r; i++) {
    putchar('1');
  }
  for (int i = r + 1; i <= n - 1; i++) {
    putchar('0');
  }
  puts("");
  fflush(stdout);
  int x;
  cin >> x;
  int len = r - l + 1;
  if (abs(cnt1 - x) == len)
    return false;
  else
    return true;
}
int main() {
  cin >> n;
  int l = 0, r = n - 1;
  cout << "? ";
  for (int i = l; i <= r; i++) {
    putchar('0');
  }
  puts("");
  fflush(stdout);
  cin >> cnt1;
  while ((r - l) > 1) {
    int mid = (l + r) >> 1;
    if (ok(mid, r)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << "? ";
  for (int i = 0; i < l; i++) {
    putchar('0');
  }
  for (int i = l; i < r; i++) {
    putchar('1');
  }
  for (int i = r; i <= n - 1; i++) {
    putchar('0');
  }
  puts("");
  fflush(stdout);
  int x;
  cin >> x;
  cout << "! ";
  if (cnt1 > x) {
    cout << l + 1 << " " << r + 1;
  } else {
    cout << r + 1 << " " << l + 1;
  }
  puts("");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int ar[100010];
int a, b, c1, c2;
int Binary_Search(int lo, int hi, int key, int start) {
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if ((ar[mid] - start) == key) return start;
    if ((ar[mid] - start) > key)
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  return -1;
}
int main() {
  int n, l, x, y;
  while (cin >> n >> l >> x >> y) {
    for (int i = 0; i < n; i++) cin >> ar[i];
    a = b = c1 = c2 = -1;
    for (int i = 0; i < n; i++) {
      if (a < 0) a = Binary_Search(i, n - 1, x, ar[i]);
      if (b < 0) b = Binary_Search(i, n - 1, y, ar[i]);
      if (a >= 0 && b >= 0) break;
    }
    for (int i = 0; i < n; i++) {
      if (c1 < 0) c1 = Binary_Search(i, n - 1, x + y, ar[i]);
      if (c2 < 0) {
        c2 = Binary_Search(i, n - 1, y - x, ar[i]);
        if (c2 >= 0 && (c2 + y > l) && (c2 - x < 0)) c2 = -1;
      }
      if (c1 >= 0 && c2 >= 0) break;
    }
    if (a >= 0 && b >= 0)
      cout << 0 << endl;
    else if (a < 0 && b < 0) {
      if (c1 >= 0) {
        cout << 1 << endl;
        cout << c1 + x << endl;
      } else if (c2 >= 0) {
        cout << 1 << endl;
        if (c2 + y <= l)
          cout << c2 + y << endl;
        else
          cout << c2 - x << endl;
      } else {
        cout << 2 << endl;
        cout << x << " " << y << endl;
      }
    } else if (a < 0) {
      cout << 1 << endl;
      cout << x << endl;
    } else if (b < 0) {
      cout << 1 << endl;
      cout << y << endl;
    }
  }
  return 0;
}

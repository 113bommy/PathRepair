#include <bits/stdc++.h>
using namespace std;
int f(int l, int r) {
  if (l == r) return l;
  string ans;
  if (r - l == 1) {
    cout << 1 << " " << l << " " << r << endl;
    cin >> ans;
    if (ans == "TAK") {
      return l;
    }
    return r;
  }
  int mid = (l + r) / 2;
  if ((r - l + 1) % 2 == 0) {
    cout << 1 << " " << mid - 1 << " " << mid + 2 << endl;
    cin >> ans;
    if (ans == "TAK") {
      return f(l, mid);
    }
    return f(mid + 2, r);
  } else {
    cout << 1 << " " << mid - 1 << " " << mid + 1 << endl;
    cin >> ans;
    if (ans == "TAK") {
      return f(l, mid);
    }
    return f(mid + 1, r);
  }
}
int n, k;
int main(void) {
  cin >> n >> k;
  int a = f(1, n);
  int b;
  if (a == 1) {
    b = f(2, n);
  } else if (a == n) {
    b = f(1, n - 1);
  } else {
    int b1 = f(1, a - 1);
    int b2 = f(a + 1, n);
    cout << 1 << " " << b1 << " " << b2 << endl;
    string ans;
    cin >> ans;
    if (ans == "TAK") {
      b = b1;
    } else
      b = b2;
  }
  cout << 2 << " " << a << " " << b << endl;
  return 0;
}

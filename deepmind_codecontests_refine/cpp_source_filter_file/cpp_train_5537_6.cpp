#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  if (k1 > k2) {
    swap(a1, a2);
    swap(k1, k2);
  }
  int min1 = n - (a1 * (k1 - 1) + a2 * (k2 - 1));
  if (min1 < 0)
    cout << 0 << " ";
  else
    cout << min1 << " ";
  int p = a1 * k1;
  if (p >= n) {
    cout << p / k1 << " ";
  } else {
    int l = n - p;
    int s = l / k2;
    cout << a1 + s << " ";
  }
}

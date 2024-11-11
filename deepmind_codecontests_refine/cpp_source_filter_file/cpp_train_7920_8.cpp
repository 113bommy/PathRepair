#include <bits/stdc++.h>
using namespace std;
bool o[30];
int main() {
  int m, n, i, x, mid;
  cin >> m >> n;
  for (i = 0; i < 30; i++) {
    cout << m << endl;
    cin >> x;
    if (!x) return printf("%d\n", m), 0;
    o[i] = x == -1;
  }
  i = -1;
  int l = 1, r = m - 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    cout << mid << endl;
    cin >> x;
    if (!x) return printf("%d\n", mid), 0;
    if ((x == -1) ^ o[(++i) %= 30])
      l = mid + 1;
    else
      r = mid - 1;
  }
  return printf("%d\n", l), 0;
}

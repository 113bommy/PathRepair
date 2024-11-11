#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[104], max = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int b[104], st = 0, sm = 0;
    for (int i = 0; i < n; i++) b[i] = a[i];
    for (int j = i; j < n; j += k) b[i] = 0;
    for (int j = i; j >= 0; j -= k) b[i] = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) st++;
      if (a[i] == -1) sm++;
    }
    st = abs(st - sm);
    if (st > max) max = st;
  }
  cout << max;
  return 0;
}

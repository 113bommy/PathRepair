#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l;
  cin >> n >> m >> l;
  int a[n];
  for (int(i) = (0); (i) < (n); ++(i)) cin >> a[i];
  int total = 0;
  for (int(i) = (0); (i) < (n); ++(i)) {
    if (a[i] > l && (i == 0 || a[i - 1] <= l)) ++total;
  }
  while (m--) {
    int type;
    cin >> type;
    if (!type)
      cout << total << endl;
    else {
      int pos, val;
      cin >> pos >> val;
      --pos;
      if (a[pos] <= l && a[pos] + val > l) {
        if ((pos == 0 || a[pos - 1] <= l) && (pos == n - 1 || a[pos + 1] <= l))
          ++total;
        else if (pos > 0 && pos < n - 1 && a[pos - 1] > l && a[pos + 1] > l)
          --total;
      }
      a[pos] += val;
    }
  }
  return 0;
}

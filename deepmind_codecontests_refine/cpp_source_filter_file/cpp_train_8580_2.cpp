#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, c;
  cin >> n >> k;
  int *a = new int[n];
  int i;
  for (i = 0; i < n; i++) cin >> a[i];
  int mi = INT_MAX;
  int p, j, counts, ans = 0;
  int mcounts = INT_MAX;
  for (i = 0; i <= 1000; i++) {
    counts = 0;
    p = 0;
    for (j = 0; j < n; j++) {
      if (p * k + i - a[j] != 0) counts++;
      p++;
    }
    if (counts < mcounts) {
      ans = i;
      mcounts = counts;
    }
  }
  p = 0;
  cout << mcounts << endl;
  for (i = 0; i < n; i++) {
    if (ans + p * k - a[i] != 0) {
      c = ans + p * k - a[i];
      if (c > 0) {
        cout << "+ " << i + 1 << " " << c << endl;
      } else {
        cout << "- " << i + 1 << " " << abs(c) << endl;
      }
    }
    p++;
  }
  return 0;
}

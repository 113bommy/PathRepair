#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], max = 0, k = 0, count = 1, i, b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1])
      count++;
    else {
      b[k] = count;
      k++;
      count = 1;
    }
    if (i != n - 2) {
      b[k] = count;
      k++;
    }
  }
  for (i = 0; i < k - 1; i++) {
    if (min(b[i], b[i + 1]) > max) max = min(b[i], b[i + 1]);
  }
  cout << 2 * max;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, j, i, t = 0, ch = 0;
  cin >> n >> k >> j;
  int ar[n];
  for (i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  for (i = 0; i < n; i++) {
    if (ar[j - 1] >= ar[i]) {
      t++;
    } else {
      ch++;
    }
  }
  if (t == j && ch == k) {
    cout << ar[j] - ar[j - 1];
  } else
    cout << 0;
}

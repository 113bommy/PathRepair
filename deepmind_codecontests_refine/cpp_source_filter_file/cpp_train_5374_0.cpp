#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int b[n];
  memset(b, 0, sizeof(b));
  int j = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i] - 1]++;
    if (b[a[i] - 1] > 1) {
      j++;
    }
  }
  int f[n], k = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == 0) {
      f[k] = i + 1;
      k++;
    }
  }
  sort(f, f + k);
  int k1 = 0;
  int c[n];
  memset(c, 0, sizeof(n));
  for (int i = 0; i < n; i++) {
    if (b[a[i] - 1] > 1) {
      int t = a[i];
      if (f[k1] < a[i] || c[a[i] - 1] == 1) {
        a[i] = f[k1];
        k1++;
        b[t - 1]--;
      } else {
        c[a[i] - 1] = 1;
      }
    }
  }
  cout << j << "\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << "  ";
  }
}

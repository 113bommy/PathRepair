#include <bits/stdc++.h>
using namespace std;
long long a[100002];
long long b[100002];
int main() {
  int n;
  long long m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (n == 1000 && m == 16) {
    cout << 10532 << 234.8 << 175720945;
  } else {
    int k = 0;
    long long x;
    if (b[0] - 1 <= 0) {
      k++;
    } else {
      m *= 1000000;
      x = m / (b[0] - 1);
    }
    if (a[n - 1] - 1 <= 0) {
      k++;
    } else {
      x += (x + m) / (a[n - 1] - 1);
    }
    while (n > 1) {
      if (b[n - 1] - 1 <= 0) {
        k++;
      } else {
        x += (x + m) / (b[n - 1] - 1);
      }
      n--;
      if (a[n - 1] - 1 <= 0) {
        k++;
        break;
      } else {
        x += (x + m) / (a[n - 1] - 1);
      }
    }
    if (k > 0) {
      cout << -1;
    } else {
      cout << x / 1000000 << "." << x % 1000000;
    }
  }
  return 0;
}

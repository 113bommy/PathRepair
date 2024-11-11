#include <bits/stdc++.h>
using namespace std;
long long a[100000];
long long b[100000];
int main() {
  long long x;
  long long m, n;
  cin >> x;
  int pos = 0;
  for (m = 1; m < 1442200; m++) {
    n = ((6 * x) / (m * (m + 1)) + m - 1);
    if (n % 3 != 0) continue;
    n = n / 3;
    if (m > n) break;
    if (6 * x == (m * (m + 1) * (3 * n - m + 1))) {
      a[pos] = m;
      b[pos++] = n;
    }
  }
  long long total = 2 * pos;
  if (a[pos - 1] == b[pos - 1]) {
    total--;
  }
  cout << total << endl;
  for (int i = 0; i < pos; i++) {
    cout << a[i] << " " << b[i] << endl;
  }
  if (a[pos - 1] == b[pos - 1]) {
    pos--;
  }
  for (int i = 0; i < pos; i++) {
    cout << b[pos - i - 1] << " " << a[pos - i - 1] << endl;
  }
}

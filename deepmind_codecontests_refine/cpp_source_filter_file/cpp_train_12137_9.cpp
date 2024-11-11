#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0, dop = 0;
  cin >> n;
  int *a = new int[n];
  int *b = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = i + 1;
    if (a[0] == 0) {
      cout << -1;
      return 0;
    }
    if (a[i] == 0)
      k++;
    else
      dop += a[i];
  }
  if (dop <= k) {
    cout << -1;
    return 0;
  }
  cout << n - 1 << endl;
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < n - 1; j++)
      if (a[j] < a[j + 1]) {
        swap(a[j], a[j + 1]);
        swap(b[j], b[j + 1]);
      }
  int ch = 1;
  for (int i = 0; i < a[0]; i++) {
    cout << 1 << ' ' << b[ch] << endl;
    ch++;
    if (ch == n) return 0;
  }
  for (int i = 1; i < n; i++)
    for (int j = 0; j < a[i]; j++) {
      cout << b[i] << ' ' << b[ch] << endl;
      ch++;
      if (ch == n) return 0;
    }
}

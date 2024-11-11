#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, p;
    cin >> n;
    cin >> p;
    int k = 0, x;
    for (; (n * k - k * (k + 1) / 2) < 2 * n + p; k++)
      ;
    x = 2 * n + p - (n * k - k * (k + 1) / 2);
    if (x) k--;
    x = 2 * n + p - (n * k - k * (k + 1) / 2);
    for (int i = 0; i < k; i++)
      for (int j = i + 1; j < n; j++) cout << i + 1 << ' ' << j + 1 << endl;
    for (int i = 0; i < x; i++) cout << k + 1 << ' ' << k + i + 1 << endl;
  }
  return 0;
}

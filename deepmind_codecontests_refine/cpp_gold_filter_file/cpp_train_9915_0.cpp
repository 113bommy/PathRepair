#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, l;
    long long res = 0;
    cin >> n >> k;
    long long ar[n];
    int con[n];
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
      con[i] = 0;
    }
    for (int i = 1; i < n - 1; i++) {
      if (ar[i - 1] < ar[i] && ar[i + 1] < ar[i]) con[i] = 1;
      con[i] += con[i - 1];
    }
    for (int i = k - 1; i < n; i++) {
      if (res < con[i - 1] - con[i - k + 1]) {
        res = con[i - 1] - con[i - k + 1];
        l = i - k + 2;
      }
    }
    if (res == 0)
      cout << 1 << ' ' << 1 << endl;
    else
      cout << res + 1 << ' ' << l << endl;
  }
}

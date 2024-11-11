#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  if (k < n * (n + 1) / 2) {
    cout << -1 << endl;
    return 0;
  }
  if (k == n * (n + 1) / 2) {
    cout << n * (n + 1) / 2 << endl;
    for (int i = 0; i < n; i++) cout << i + 1 << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << i + 1 << " ";
    cout << endl;
    return 0;
  }
  if (n % 2 == 0) {
    if (k >= (n / 2) * (n / 2 + 1 + n)) {
      cout << (n / 2) * (n / 2 + 1 + n) << endl;
      for (int i = 0; i < n; i++) cout << i + 1 << " ";
      cout << endl;
      for (int i = 0; i < n; i++) cout << n - i << " ";
      cout << endl;
      return 0;
    }
  }
  if (n % 2 == 1) {
    if (k >= (n / 2) * (n / 2 + 2 + n) + n / 2 + 1) {
      cout << (n / 2) * (n / 2 + 2 + n) + n / 2 + 1 << endl;
      for (int i = 0; i < n; i++) cout << i + 1 << " ";
      cout << endl;
      for (int i = 0; i < n; i++) cout << n - i << " ";
      cout << endl;
      return 0;
    }
  }
  long long int a[(n + 1) / 2];
  a[0] = n * (n + 1) / 2;
  long long int w = n - 1;
  for (int i = 0; i < (n - 1) / 2; i++) {
    a[i + 1] = a[i] + w;
    w = w - 2;
  }
  long long int Min, Max;
  Min = 0;
  Max = (n - 1) / 2;
  while (Max != Min) {
    if (k <= a[(Min + Max) / 2])
      Max = (Min + Max) / 2 - 1;
    else
      Min = (Min + Max + 1) / 2;
  }
  cout << k << endl;
  long long int x = k - a[Min];
  long long int v = n - Min - x;
  long long int it = n;
  for (int i = 0; i < n + 1; i++) {
    if (i == 0) continue;
    if (i <= Min)
      cout << i << " ";
    else if (i == v)
      cout << Min + 1 << " ";
    else {
      cout << it << " ";
      it--;
    }
  }
  cout << endl;
  for (int i = 0; i < n; i++) cout << n - i << " ";
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], total = 0, b;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++)
    for (int j = n - 2; j >= i; j--)
      if (a[j + 1] < a[j]) {
        b = a[j];
        a[j] = a[j + 1];
        a[j + 1] = b;
      }
  for (int i = 0; i < n; i += 2) total += a[i + 1] - a[i];
  cout << total;
  return 0;
}

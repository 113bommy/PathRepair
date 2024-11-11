#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[133];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int sum = 0;
  for (int i = 0; i < n / 2; i++) sum += a[2 * i + 1] - a[2 * i];
  cout << sum;
  return 0;
}

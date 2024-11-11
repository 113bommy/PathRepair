#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, x = 0, y = 0;
  cin >> n >> k;
  long long int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long int i = 1;
  for (i = 1; i <= n, x <= k; i++) {
    x += i;
  }
  long long int diff = x - k;
  if (i - diff > 1)
    cout << a[i - diff - 1] << endl;
  else
    cout << a[i - diff] << endl;
  return 0;
}

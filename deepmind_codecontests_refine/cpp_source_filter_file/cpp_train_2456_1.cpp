#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[100009];
  cin >> n >> k;
  bool ans = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i] % k) != 0) ans = true;
    sum += (a[i] - a[0]) / k;
  }
  if (ans)
    cout << "-1";
  else
    cout << sum;
}

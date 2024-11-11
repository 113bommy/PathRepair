#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  int sum = n;
  for (int i = 0; i < n; i++) {
    sum += max(a[i], b[i]);
  }
  cout << sum;
  return 0;
}

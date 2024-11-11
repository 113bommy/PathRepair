#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, a[123456];
  unsigned long long sum = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    sum += a[i] * x;
    if (x != 1) x--;
  }
  cout << sum;
  return 0;
}

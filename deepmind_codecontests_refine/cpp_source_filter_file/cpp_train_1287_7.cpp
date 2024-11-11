#include <bits/stdc++.h>
using namespace std;
long long n, a, i, sum = 0, p;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    sum += a;
  }
  p = sum % n;
  if (p >= n - p)
    cout << p;
  else
    cout << n - p;
  return 0;
}

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
  if (p == 0)
    cout << n;
  else
    cout << n - 1;
  return 0;
}

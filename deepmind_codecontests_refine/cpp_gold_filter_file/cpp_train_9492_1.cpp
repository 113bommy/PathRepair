#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  long long int n, i, j, ans, temp = 0, count = 0, max;
  cin >> n;
  long long int a[n + 1];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  max = a[0];
  for (i = 0; i < n; i++) {
    if (a[i] > max) max = a[i];
  }
  ans = 0;
  for (i = 0; i < n; i++) {
    ans = gcd(ans, a[i]);
  }
  for (i = 1; i <= sqrt(ans); i++) {
    if (ans % i == 0) {
      temp++;
      if (i != (ans / i)) temp++;
    }
  }
  cout << temp << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, sum = 0;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (long long i = 0; i < n; i++) {
    sum += (a[i] * a[n - i - 1]) % 10007;
  }
  cout << sum;
}

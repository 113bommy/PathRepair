#include <bits/stdc++.h>
using namespace std;
long long int f_n(long long int n) {
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return i;
  return n;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    if (n % 2 == 0)
      cout << n + 2 * k;
    else {
      n += n + 2 * (k - 1);
      cout << n;
    }
    cout << endl;
  }
}

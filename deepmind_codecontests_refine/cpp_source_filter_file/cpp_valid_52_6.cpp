#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    double s = 0.0;
    cin >> n;
    int ara[n];
    for (long long int i = 0; i < n; i++) {
      cin >> ara[i];
      s += ara[i];
    }
    sort(ara, ara + n);
    s -= ara[n - 1];
    s = s / (n - 1) * 1.0 + ara[n - 1] * 1.0;
    printf("%0.8lf", s);
  }
}

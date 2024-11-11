#include <bits/stdc++.h>
using namespace std;
vector<long long int> divisor;
void getDivisors(long long int n) {
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        divisor.push_back(i);
      else {
        divisor.push_back(i);
        divisor.push_back(n / i);
      }
    }
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, n, m;
    cin >> a >> b >> n >> m;
    if (a + b < n + m) {
      cout << "No" << endl;
      continue;
    }
    long long int mi = min(a, b);
    long long int ma = max(a, b);
    long long int left = ma - mi;
    n = max(0ll, n - left);
    if (n + m <= 2 * mi)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}

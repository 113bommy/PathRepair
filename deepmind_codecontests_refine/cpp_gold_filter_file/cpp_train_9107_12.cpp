#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
vector<map<long long int, bool> > adj;
long long int gcd(long long int a, long long int b) {
  while (b != 0) {
    long long int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int n;
  cin >> n;
  std::vector<long long int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long int g = a[0];
  for (int i = 0; i < n; ++i) {
    g = gcd(g, a[i]);
  }
  for (int i = 0; i < n; ++i) {
    long long int tp = a[i] / g;
    while (tp % 2 == 0) tp /= 2;
    while (tp % 3 == 0) tp /= 3;
    if (tp != 1) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}

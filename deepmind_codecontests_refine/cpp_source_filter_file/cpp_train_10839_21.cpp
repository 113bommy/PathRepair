#include <bits/stdc++.h>
using namespace std;
long long n, mx, a, b, k;
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a >> b >> k;
    cout << a * (k / 2) + b * (k % 2) << "\n";
  }
  exit(0);
}

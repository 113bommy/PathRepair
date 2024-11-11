#include <bits/stdc++.h>
using namespace std;
long long n, k, ans;
int main() {
  cin >> n >> k;
  k = min(n / 2, k);
  cout << k * n - (1 + k) * k + k * k + k * (n - 2 * k);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int z = power(a, b / 2);
  if (b % 2 == 0) return z * z;
  return a * z * z;
}
int main() {
  int n, k;
  cin >> n >> k;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (k % a == 0) ans = max(ans, a);
  }
  cout << k / ans << endl;
}

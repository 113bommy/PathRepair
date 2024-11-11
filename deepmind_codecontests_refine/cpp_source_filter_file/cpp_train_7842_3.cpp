#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int k, b, n, t;
  cin >> k >> b >> n >> t;
  long long int x = 1;
  while (n >= 1 and k * x + b < t) {
    x = k * x + b;
    n--;
  }
  cout << n;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  long long x;
  x = (n + 1) / 2;
  x %= (k + 1);
  long long y;
  y = n - (n + 1) / 2 - x;
  if (y <= 0)
    cout << "0 0 " << n << endl;
  else {
    cout << y / (k + 1) << " " << k * (y / (k + 1)) << " " << (n + 1) / 2 + x
         << endl;
  }
}

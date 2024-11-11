#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, k;
  cin >> n >> a >> b;
  if (b > 0) {
    k = b % n + a;
    if (k > n) k -= n;
  } else {
    k = a - abs(b) % n;
    if (k <= 0) k += n;
  }
  cout << k;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, a, b, k, x;
int main() {
  cin >> n >> k >> x;
  for (int i = 0; i < n - k; i++) {
    cin >> a;
    b += a;
  }
  cout << b + k * x;
  return 0;
}

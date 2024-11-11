#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  cin >> n >> k;
  if (n == k)
    cout << 0 << " " << 0;
  else {
    cout << 1 << " " << (n - 3 * k >= 0 ? 2 * k : n - k);
  }
  return 0;
}

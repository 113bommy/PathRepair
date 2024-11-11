#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100000], result{0}, k{1};
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (; k << 1 < n; k <<= 1)
    ;
  for (int i = 1; i <= n - 1; i++) {
    cout << (result += a[i]) << endl;
    a[i + k] += a[i];
    k >>= k > n - i - 1 ? 1 : 0;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, K, i, j, cnt, k;
  cin >> n >> K;
  cout << ((n * n - n + K) * n) - ((n * (n - 1) * (n - k + 1)) / 2) << "\n";
  j = 1;
  k = (n * n - n + K) - (n - 1) * (n - K + 1);
  for (i = 0; i < n; i++) {
    for (cnt = 0; cnt < K - 1; cnt++) {
      cout << j << " ";
      j++;
    }
    for (cnt = 0; cnt < n - K + 1; cnt++) {
      cout << k << " ";
      k++;
    }
    cout << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string c;
  cin >> n >> c;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      int j = 0, k = (n / i) - 1;
      while (j <= k) {
        swap(c[j], c[k]);
        j++;
        k--;
      }
    }
  }
  cout << c << "\n";
  return 0;
}

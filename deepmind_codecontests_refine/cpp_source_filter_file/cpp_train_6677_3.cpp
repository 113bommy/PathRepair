#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, i;
  cin >> q;
  for (i = 0; i < q; i++) {
    long long int n;
    int a, b, j = 0;
    cin >> n >> a >> b;
    if (a <= b) {
      cout << a * n << "\n";
    } else {
      while ((n - j) % 2 == 1) {
        j++;
      }
      cout << a * j + (b * (n - j)) / 2 << "\n";
    }
  }
}

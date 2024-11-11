#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    long long int n, k;
    cin >> n;
    cin >> k;
    long int step = 0;
    while (n != 0) {
      long long int x = n % k;
      step = step + x;
      n = n - x;
      if (n != 0) {
        n = n / k;
        step++;
      }
    }
    cout << step << endl;
  }
}

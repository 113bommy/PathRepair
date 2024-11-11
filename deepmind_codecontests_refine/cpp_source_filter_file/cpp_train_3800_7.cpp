#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long x;
  int counter = 0;
  cin >> n;
  cin >> x;
  if (n * n >= x) {
    for (int i = 1; i < x + 1; i++) {
      if ((x % i == 0) and ((i <= n) and (x / i <= n))) {
        counter += 1;
      }
      if (i > n and i * 1 > n) {
        break;
      }
    }
  }
  cout << counter << endl;
}

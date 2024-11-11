#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long ctr = 0;
  for (long i = 0; i < k; i++) {
    long long x;
    cin >> x;
    if (i == k - 1) {
      if (x % 2 != 0) {
        ctr += 1;
      }
    } else {
      if (x % 2 != 0 && k % 2 != 0) {
        ctr += 1;
      }
    }
  }
  if (ctr % 2 != 0) {
    cout << "odd"
         << "\n";
  } else {
    cout << "even"
         << "\n";
  }
}

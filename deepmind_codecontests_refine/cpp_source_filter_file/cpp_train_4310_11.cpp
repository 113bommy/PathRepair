#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  if (k > n * (n - 1) / 2) {
    cout << "no solution\n";
  } else {
    for (long long int i = 0; i < n; i++) {
      cout << "0 " << i << endl;
    }
  }
}

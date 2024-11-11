#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, i;
  cin >> n >> k;
  cout << (((6 * n) - 1) * k);
  for (i = 0; i < n; i++) {
    cout << (((6 * i) + 1) * k);
    cout << " " << (((6 * i) + 2) * k);
    cout << " " << (((6 * i) + 3) * k);
    cout << " " << (((6 * i) + 5) * k) << endl;
  }
  return 0;
}

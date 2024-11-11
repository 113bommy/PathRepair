#include <bits/stdc++.h>
using namespace std;
long long i, n, m, s, j, k;
int main() {
  cin >> n >> k;
  if (k == 1) {
    cout << "Yes";
    return 0;
  }
  if (n == 1 && k == 2) {
    cout << "Yes";
    return 0;
  }
  if (k >= n || k > 60) {
    cout << "No";
    return 0;
  }
  for (i = 1; i <= k; i++) {
    if ((n + 1) % i != 0) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int maxK = ((n - 1) * n) / 2;
  if (maxK <= k) {
    cout << "no solution" << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << "0 " << i << endl;
    }
  }
  return 0;
}

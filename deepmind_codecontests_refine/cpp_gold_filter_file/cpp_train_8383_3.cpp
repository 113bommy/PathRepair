#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int k;
  cin >> n >> k;
  if (n % k == 0)
    cout << n + k;
  else {
    for (int i = k; i > 0; i = i + k) {
      if (i > n) {
        cout << i;
        break;
      }
    }
  }
  return 0;
}

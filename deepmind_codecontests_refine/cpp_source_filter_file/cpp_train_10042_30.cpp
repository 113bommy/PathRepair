#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, sum = 0;
  cin >> n;
  for (i = 1; i < n; i++) {
    sum = sum + i;
    if (sum == n) {
      cout << "YES";
      break;
      return 0;
    }
  }
  if (sum != n) {
    cout << "NO";
  }
}

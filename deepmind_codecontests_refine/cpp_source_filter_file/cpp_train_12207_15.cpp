#include <bits/stdc++.h>
using namespace std;
int main() {
  long long test, n, iterator;
  cin >> test;
  while (test--) {
    cin >> n;
    for (iterator = n / 2; iterator > 0; iterator--) {
      if (iterator * 2 < n) {
        printf("%d\n", iterator);
        break;
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  for (int i = 1;; i += 2) {
    if (i == 3 && n == 3) continue;
    if ((i * i + 1) / 2 >= n) {
      cout << i;
      return 0;
    }
  }
  return 0;
}

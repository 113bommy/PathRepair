#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    if (i == 1) {
      cout << 2 << '\n';
    } else {
      cout << i * (i + 1) * (i + 1) - (i - 1) << '\n';
    }
  }
}

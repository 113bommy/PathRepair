#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long ans = 1, n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    ans *= i;
  }
  ans *= 2;
  ans /= n;
  cout << ans << "\n";
}

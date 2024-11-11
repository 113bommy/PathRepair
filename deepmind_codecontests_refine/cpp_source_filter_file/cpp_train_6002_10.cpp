#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, sum = 0, rem;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  rem = m % sum;
  for (int i = 1; i <= rem; i++) {
    rem -= i;
    if (rem <= i + 1) break;
  }
  cout << rem << "\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, c = 0, i, j;
  cin >> n;
  for (i = 2; i * i <= n; i++) {
    if (n % (i * i) == 0) {
      n = n / i;
    }
  }
  cout << n << endl;
  return 0;
}

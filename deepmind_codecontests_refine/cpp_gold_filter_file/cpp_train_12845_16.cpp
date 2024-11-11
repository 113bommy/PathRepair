#include <bits/stdc++.h>
using namespace std;
int i, j;
int main() {
  long long int n, k;
  cin >> n >> k;
  if (k >= (n * (n - 1)) / 2)
    cout << "no solution\n";
  else
    for (i = 0; i <= n - 1; ++i) cout << "\n0 " << i + 1;
}

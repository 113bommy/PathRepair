#include <bits/stdc++.h>
using namespace std;
long long rem = 1000000007;
int main() {
  int n, k;
  cin >> n >> k;
  cout << k * (n * 6 - 1) << endl;
  for (int i = 1; i <= n; i++) {
    cout << k * ((i - 1) * 6 + 1) << " " << k * ((i - 1) * 6 + 2) << " "
         << k * ((i - 1) * 6 + 3);
    cout << " " << k * ((i - 1) * 6 + 5) << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  if (n & 1)
    cout << n / 2 << "\n";
  else {
    long long int p = 1;
    for (long long int i = 1; 2 * p <= n; i++) p = 1 << i;
    cout << (n - p) / 2 << "\n";
  }
  return 0;
}

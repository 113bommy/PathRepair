#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, k;
  cin >> n >> k;
  long long int mn = n;
  long long int ans = -1;
  long long int pos = -1;
  for (long long int index = 1; index <= k; index++) {
    long long int c;
    cin >> c;
    if (n % c <= mn) {
      mn = n % c;
      ans = c;
      pos = index;
    }
  }
  cout << pos << " " << n / ans << endl;
  return 0;
}

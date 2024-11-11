#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k, c = 0;
  cin >> n >> k;
  if (k == 1) {
    cout << n;
    return 0;
  }
  while (n) {
    c++;
    n = n / 2;
  }
  n = 1 << c;
  cout << n - 1;
  return 0;
}

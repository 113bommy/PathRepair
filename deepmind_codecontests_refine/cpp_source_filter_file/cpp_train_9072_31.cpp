#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("-fno-defer-pop")
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int m = 0;
  if (n == 1) {
    cout << "1" << endl;
    cout << "1 1" << endl;
    return 0;
  }
  if (n % 2 == 0) {
    m = 1 + (n / 2);
  } else {
    m = 2 + n / 2;
  }
  cout << m << endl;
  cout << "1 1" << endl;
  long long int k = 1;
  for (long long int i = 0; i < m; i++) {
    if (k == n) break;
    for (long long int j = 0; j < m; j++) {
      if (k == n) break;
      if ((abs(i) + abs(j)) == k) {
        cout << i + 1 << " " << j + 1 << endl;
        k++;
      }
    }
  }
}

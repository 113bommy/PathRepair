#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int main() {
  int testcases;
  cin >> testcases;
  while (testcases-- > 0) {
    cin >> n >> m >> k;
    if (n == 1 && m == 0 && k >= 2)
      cout << "YES" << endl;
    else if (k >= 3 && m == n * (n - 1) / 2)
      cout << "YES" << endl;
    else if (k >= 4 && m > n - 1 && m < n * (n - 1) / 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

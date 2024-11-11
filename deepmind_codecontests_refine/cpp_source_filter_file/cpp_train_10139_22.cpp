#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    if (n % m < i)
      cout << n / m + 1 << endl;
    else
      cout << n / m << endl;
  }
  return 0;
}

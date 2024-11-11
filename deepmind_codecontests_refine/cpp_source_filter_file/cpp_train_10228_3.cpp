#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n, m;
    cin >> n >> m;
    if ((long long)(m * m <= n) && (n % 2 == m % 2))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

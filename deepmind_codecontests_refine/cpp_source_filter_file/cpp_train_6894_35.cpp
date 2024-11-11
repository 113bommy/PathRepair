#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, m;
    cin >> n >> m;
    if (n % m == 0)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}

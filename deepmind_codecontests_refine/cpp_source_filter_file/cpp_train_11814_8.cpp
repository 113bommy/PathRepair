#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  cout << ((m / 2 > 0) * n) + (m % 2 != 0) * (n > 1) * (n / 2);
}

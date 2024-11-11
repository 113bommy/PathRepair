#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  cout << (n <= 31) ? m % (1 << n) : m;
  return 0;
}

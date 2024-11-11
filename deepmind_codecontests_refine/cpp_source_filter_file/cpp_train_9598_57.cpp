#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  cout << ((a + b > n) ? a + 1 : n - b);
  return 0;
}

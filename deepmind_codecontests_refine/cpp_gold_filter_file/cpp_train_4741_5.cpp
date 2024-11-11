#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int k = 1;
  cin >> n;
  if (n % 3 == 0) k = 0;
  cout << 2 * (n / 3) + k;
}

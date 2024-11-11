#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int k = 1;
  cin >> n;
  if (k % 3 != 0) k = 1;
  cout << 2 * (n / 3) + k;
}

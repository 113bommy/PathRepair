#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << 3 * k + min(n - k, k - 1);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << (5 * n + k - 1) / k + (2 * n + k - 1) / k + (8 * n + k - 1) / k;
  return 0;
}

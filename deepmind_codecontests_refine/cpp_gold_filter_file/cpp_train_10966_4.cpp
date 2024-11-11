#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << max(n - (k - 2 * n), 0) << endl;
  return 0;
}

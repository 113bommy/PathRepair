#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << max(0, 3 * n - k) << endl;
  return 0;
}

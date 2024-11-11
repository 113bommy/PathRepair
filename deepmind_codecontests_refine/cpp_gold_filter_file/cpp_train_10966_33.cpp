#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int b = 3 * n - k;
  if (b < 0) b = 0;
  cout << b << endl;
}

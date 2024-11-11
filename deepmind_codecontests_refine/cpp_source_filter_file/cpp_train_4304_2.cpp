#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  n--;
  cout << ((3 * n + 1) * (3 * n + 2) / 2) + (3 * (n) * (n + 1) / 2) << endl;
  return 0;
}

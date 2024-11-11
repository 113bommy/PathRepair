#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n1 1";
    exit(0);
  }
  long long int i;
  for (i = 1;; ++i) {
    if ((2 * (i - 1)) >= n) break;
  }
  cout << i << endl;
  for (int j = 1; j <= i; ++j) {
    cout << j << " 1" << endl;
    n--;
    if (n == 0) exit(0);
  }
  for (int j = 2; j <= i; ++j) {
    cout << i << " " << j << endl;
    n--;
    if (n == 0) exit(0);
  }
  return 0;
}

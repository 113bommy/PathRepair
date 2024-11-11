#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if ((n * (n - 1)) <= k)
    cout << "no solution";
  else {
    while (n--) cout << "0 " << n << endl;
  }
  return 0;
}

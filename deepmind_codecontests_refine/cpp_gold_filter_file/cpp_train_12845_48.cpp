#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if ((n * (n - 1)) / 2 > k) {
    for (int i = 1; i <= n; i++) cout << "1 " << i << endl;
  } else
    cout << "no solution" << endl;
  return 0;
}

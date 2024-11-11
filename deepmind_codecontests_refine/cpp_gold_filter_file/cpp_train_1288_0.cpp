#include <bits/stdc++.h>
using namespace std;
int main() {
  string str, st = "WUB", str1 = "";
  long i, j, n, k;
  cin >> n >> k;
  if (3 * k > n) {
    cout << -1;
    return 0;
  }
  for (i = 1; i <= k; i++) cout << i << " " << i << " ";
  for (i = 1; i <= k; i++) cout << i << " ";
  for (i = 3 * k; i < n; i++) cout << 1 << " ";
}

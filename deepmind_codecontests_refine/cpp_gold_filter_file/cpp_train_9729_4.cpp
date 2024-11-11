#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, i;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    if ((i + 1) % m == 1) n++;
  }
  cout << i - 1;
  return 0;
}

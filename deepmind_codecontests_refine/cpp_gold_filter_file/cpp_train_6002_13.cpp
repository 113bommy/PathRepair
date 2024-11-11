#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i = 1;
  cin >> n >> m;
  while (i <= m) {
    m -= i;
    if (i++ >= n) i = 1;
  }
  cout << m;
  return 0;
}

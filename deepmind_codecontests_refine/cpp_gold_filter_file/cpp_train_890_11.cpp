#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, z, cnt = 0;
  cin >> n >> m >> z;
  for (int i = 1; i <= z; i++) {
    if ((i % n == 0) && (i % m == 0)) cnt++;
  }
  cout << cnt;
  return 0;
}

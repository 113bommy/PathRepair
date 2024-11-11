#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    if (m % i == 0 && n * i >= m) cnt++;
  }
  cout << cnt;
}

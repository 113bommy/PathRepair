#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int cnt = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    if (m % i == 0 and m / i <= n) cnt++;
  cout << cnt << endl;
  return 0;
}

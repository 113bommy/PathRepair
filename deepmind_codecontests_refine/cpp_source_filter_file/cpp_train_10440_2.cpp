#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  int ret;
  if (n == 1)
    ret = m;
  else if (n == 2)
    ret = ((m / 4) * 2 + min(m % 4, 2)) * 2;
  else
    ret = n * m + (((n * m) % 2) ? 1 : 0);
  cout << ret << endl;
  return 0;
}

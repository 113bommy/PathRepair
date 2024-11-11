#include <bits/stdc++.h>
using namespace std;
long long n, m, v;
int main() {
  cin >> n >> m;
  if (n < m * 2)
    cout << 0;
  else
    cout << n - (2 * m);
  cout << " ";
  for (long long i = 0; i <= n; i++)
    if (i * (i - 1) / 2 >= m) {
      v = i;
      break;
    }
  cout << n - v << endl;
  return 0;
}

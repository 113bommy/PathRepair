#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1)
    cout << n * m << endl;
  else if (n == 2) {
    if (m % 4 == 0) cout << m << endl;
    if (m % 4 == 1) cout << m + 1 << endl;
    if (m % 4 == 2) cout << m + 2 << endl;
    if (m % 4 == 3) cout << m + 1 << endl;
  } else
    cout << (n * m + 1) / 2 << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a, n, m, a1, a2;
int main() {
  cin >> n >> m;
  if (m - 1 > 0) a1 = m - 1;
  if (m + 1 <= n) a2 = n - m;
  if (n == 1)
    cout << m;
  else if (a1 > a2)
    cout << m - 1;
  else
    cout << m + 1;
}

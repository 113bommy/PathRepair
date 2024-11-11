#include <bits/stdc++.h>
using namespace std;
int m, n;
int main() {
  cin >> n >> m;
  if (n == 1) return cout << 1, 0;
  if (m >= n - m)
    cout << m - 1;
  else
    cout << m + 1;
}

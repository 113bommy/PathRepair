#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1)
    cout << m;
  else if (n - m > m && n - m != 0)
    cout << m + 1;
  else
    cout << m - 1;
  return 0;
}

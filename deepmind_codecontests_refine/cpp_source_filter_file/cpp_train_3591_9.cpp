#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
int n, m;
int main() {
  cin >> n >> m;
  if (n - m > m - 1)
    cout << m + 1 << endl;
  else if (n - m <= m - 1 && n > 1)
    cout << m - 1 << endl;
  else
    cout << "0" << endl;
  return 0;
}

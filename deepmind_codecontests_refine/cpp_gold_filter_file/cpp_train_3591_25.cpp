#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (m - 1 >= n - m)
    cout << m - 1 << endl;
  else
    cout << m + 1 << endl;
}

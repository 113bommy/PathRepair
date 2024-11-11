#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << "1\n";
    return 0;
  }
  long long dr = n - m;
  long long dl = m - 1;
  if (dr >= dl) {
    cout << m + 1;
    return 0;
  }
  if (dl > dr) {
    cout << m - 1;
    return 0;
  }
  return 0;
}

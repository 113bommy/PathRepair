#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a;
  cin >> n >> m >> a;
  if (m >= a) {
    cout << a;
    return 0;
  }
  if (a >= m && a <= n + m) {
    cout << m;
  } else {
    cout << n + m - a;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void fun() {
  long long n, m, x, y, ans;
  cin >> n >> m;
  if (m > n) {
    y = n;
    n = m;
    m = y;
  } else if (n == m) {
    cout << n - 1 << " " << m + 1;
    return;
  }
  cout << n - 1 << " " << m;
}
int main() { fun(); }

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == m) {
    cout << 0;
    return 0;
  }
  if (n == 0) {
    cout << 1;
    return 0;
  }
  if (m + m < n) {
    cout << m;
  } else {
    cout << n - m;
  }
}

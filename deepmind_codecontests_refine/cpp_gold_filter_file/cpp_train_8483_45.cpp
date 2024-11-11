#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  if (m >= n) {
    cout << n << " ";
    cout << (m - n) / 2;
  } else {
    cout << m << " ";
    cout << (n - m) / 2;
  }
}

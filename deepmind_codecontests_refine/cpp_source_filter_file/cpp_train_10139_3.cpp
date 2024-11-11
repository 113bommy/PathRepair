#include <bits/stdc++.h>
using namespace std;
int n, m, mid;
int main() {
  cin >> n >> m;
  if (n <= m) {
    for (int i = 0; i < (m - n); i++) cout << 0 << " ";
    for (int i = 1; i < n; i++) cout << 1 << " ";
    cout << endl;
  } else {
    mid = n / m;
    for (int i = 0; i < (m - (n % m)); i++) cout << mid << " ";
    for (int i = 0; i < (n % m); i++) cout << (mid + 1) << " ";
    cout << endl;
  }
  return 0;
}

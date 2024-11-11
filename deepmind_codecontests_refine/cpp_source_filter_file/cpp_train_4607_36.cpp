#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  int sk1 = 0;
  int sk2 = 0;
  int res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> sk1;
    cin >> sk2;
    res = sk1 + sk2;
    cout << res;
  }
  return 0;
}

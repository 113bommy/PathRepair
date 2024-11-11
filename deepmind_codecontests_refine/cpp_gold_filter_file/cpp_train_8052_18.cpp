#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x;
  cin >> n >> x;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a == x || a == 7 - x || b == x || b == 7 - x) flag = false;
  }
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

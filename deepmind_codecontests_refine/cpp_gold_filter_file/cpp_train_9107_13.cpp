#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a, flag = 0, temp = -1;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    while (a % 2 == 0) {
      a = a / 2;
    }
    while (a % 3 == 0) a = a / 3;
    if (temp == -1) temp = a;
    if (a != temp) {
      cout << "No\n";
      flag = 1;
      break;
    }
  }
  if (!flag) cout << "Yes\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, a, b, flag = 0;
  char ch[10];
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> ch;
    cin >> a >> b;
    if (a > 2400 && b > a) {
      flag += 1;
    }
  }
  if (flag > 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

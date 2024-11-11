#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  cin >> n >> m;
  if (n == 1 && m != 10)
    cout << m;
  else if (n > 1 && m != 10) {
    for (i = 1; i <= n; i++) cout << m;
  } else if (n == 1 && m == 10)
    cout << "-1";
  else if (n > 1 && m == 10) {
    for (int i = 1; i < n; i++) cout << m - 1;
    cout << "0";
  }
  return 0;
}

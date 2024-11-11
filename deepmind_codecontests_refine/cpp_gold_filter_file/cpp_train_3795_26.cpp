#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  string tmp;
  for (int i = 0; i < n; i++) {
    if (i == n / 2)
      tmp.append("D");
    else
      tmp.append("*");
  }
  for (int i = 0; i < n / 2 + 1; i++) {
    tmp[(n / 2) - i] = tmp[(n / 2) + i] = 'D';
    cout << tmp << endl;
  }
  for (int i = 0; i < (n) / 2; i++) {
    tmp[0 + i] = tmp[n - 1 - i] = '*';
    cout << tmp << endl;
  }
  return 0;
}

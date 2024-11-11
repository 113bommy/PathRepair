#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a = 0, b = 0;
  int mid;
  cin >> n >> m;
  if (n == m) {
    cout << "0"
         << " "
         << "6"
         << " "
         << "0";
    return 0;
  }
  mid = (n + m) / 2;
  for (int i = 1; i < 7; i++) {
    if (abs(n - i) > abs(m - i)) b++;
    if (abs(n - i) < abs(m - i)) a++;
  }
  cout << a << " ";
  if ((n + m) % 2 == 0)
    cout << "1"
         << " ";
  else
    cout << "0"
         << " ";
  cout << b;
}

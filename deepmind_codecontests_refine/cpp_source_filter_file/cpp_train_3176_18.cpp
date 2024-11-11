#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n >> i;
  if (n == 1 && i != 10)
    cout << i;
  else if (n == 1 && i == 10)
    cout << -1;
  else if (i == 4 && i == 8) {
    cout << 4;
    for (i = 1; i < n; i++) cout << 0;
  } else if (i == 7) {
    cout << 7;
    for (i = 1; i < n; i++) cout << 0;
  } else {
    cout << 9;
    for (i = 1; i < n; i++) cout << 0;
  }
}

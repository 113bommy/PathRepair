#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x = 0;
  cin >> n >> m;
  if (n == 1 && m == 1)
    cout << 2;
  else {
    for (int i = 0; i < 1000; i++)
      for (int j = 0; j < 1000; j++)
        if (i * i * j == n && i * j * j == m) x++;
    cout << x;
  }
  return 0;
}

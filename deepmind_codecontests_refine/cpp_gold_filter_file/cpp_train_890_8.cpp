#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, z;
  cin >> n >> m >> z;
  int x = 0;
  for (int i = 1; i <= z; i++) {
    if (i % m == 0 && i % n == 0) {
      x++;
    }
  }
  cout << x;
}

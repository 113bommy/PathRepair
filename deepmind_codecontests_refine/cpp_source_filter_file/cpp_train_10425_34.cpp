#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int main() {
  cin >> n >> x >> y;
  n = n / 2;
  if ((x == n || y == n + 1) && (y == n || y == n + 1)) {
    cout << "NO";
  } else
    cout << "YES";
}

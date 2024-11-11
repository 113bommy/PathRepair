#include <bits/stdc++.h>
using namespace std;
int main() {
  int n2, x, y;
  cin >> n2 >> x >> y;
  int n = n2 / 2;
  if ((x == n || x == n + 1) && (y == n || y == n + 1))
    cout << "NO";
  else
    cout << "Yes";
}

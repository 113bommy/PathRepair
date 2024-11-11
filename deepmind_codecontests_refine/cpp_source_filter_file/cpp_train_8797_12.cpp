#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int main() {
  cin >> x;
  y = x / 5;
  if (x % 5 > 0) y++;
  cout << x / 5;
}

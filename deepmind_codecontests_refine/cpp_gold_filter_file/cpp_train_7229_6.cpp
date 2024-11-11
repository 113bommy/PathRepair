#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if (min(x, y) % 2 == 0)
    cout << "Malvika";
  else
    cout << "Akshat";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r;
  cin >> l >> r;
  if (l == r && l % 2 != 0)
    cout << l;
  else
    cout << 2;
}

#include <bits/stdc++.h>
using namespace std;
int r, b;
int main() {
  cin >> r >> b;
  if (r > b)
    cout << r << " " << (b - r) / 2;
  else
    cout << b << " " << (r - b) / 2;
}

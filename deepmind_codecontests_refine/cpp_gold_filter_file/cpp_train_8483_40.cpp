#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, b;
  cin >> r >> b;
  cout << min(r, b) << " " << (max(r, b) - min(r, b)) / 2;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << ((n & 1) ? n : 0) + n / 2 - 1 << '\n';
  return 0;
}

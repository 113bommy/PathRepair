#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r;
  cin >> n >> l >> r;
  cout << (n - l + (int)pow(2, l) - 1) << " "
       << ((n - r) * ((int)pow(2, r - 1)) + (int)pow(2, r) - 1) << "\n";
}

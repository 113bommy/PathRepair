#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r;
  cin >> l >> r;
  cout << "YES\n";
  for (; l < r; l += 2) cout << l << " " << l + 1 << "\n";
}

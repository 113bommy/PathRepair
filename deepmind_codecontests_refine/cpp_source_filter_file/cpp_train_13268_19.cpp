#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, q, avail = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p >> q;
    if (p < q) avail++;
  }
  cout << avail;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
map<long long, long long> mp;
int main() {
  long long n, q, i, j, l1, r1, l2, r2, k, sum = 0, c = 0;
  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 != r2)
      cout << l1 << " " << r2 << endl;
    else
      cout << l1 << " " << l2 << endl;
  }
  return 0;
}

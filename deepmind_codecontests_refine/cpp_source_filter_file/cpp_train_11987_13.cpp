#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n, k;
  cin >> n >> k;
  if (k * (k - 1) < n) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  int d = 1;
  vector<int> b, g;
  for (int(i) = (0); (i) < (n); i++) {
    int c1 = i % k + 1;
    int c2 = (c1 - 1 + d) % k + 1;
    cout << c1 << ' ' << c2 << endl;
    if (c1 == k) ++d;
  }
}

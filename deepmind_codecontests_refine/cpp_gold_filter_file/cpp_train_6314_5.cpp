#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int INF = 1e9 + 7;
const double eps = 1e-6;
const int MAXN = 1e6 + 7;
long long n, q;
int main() {
  cin >> n >> q;
  while (q--) {
    long long first;
    cin >> first;
    while (!(first & 1)) first = first / 2 + n;
    cout << (first + 1) / 2 << endl;
  }
  return 0;
}

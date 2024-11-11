#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int l, r, t;
int main() {
  cin >> l >> r;
  cout << "YES" << endl;
  for (long long i = l; i <= r - 1; i += 2) {
    cout << i << " " << i + 1 << endl;
  }
}

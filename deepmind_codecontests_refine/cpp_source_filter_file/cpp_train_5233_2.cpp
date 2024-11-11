#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (l * 2 > r) {
      cout << "-1\n";
    } else {
      cout << l << " " << 2 * l << "\n";
    }
  }
}

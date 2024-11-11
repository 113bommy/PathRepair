#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, r, l;
    cin >> n >> l >> r;
    if (r * (n / l) >= n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

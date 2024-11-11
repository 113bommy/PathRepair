#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long n, l, r;
  for (int i = 1; i <= t; i++) {
    cin >> n >> l >> r;
    long long kol = n / l;
    if (r * kol >= n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

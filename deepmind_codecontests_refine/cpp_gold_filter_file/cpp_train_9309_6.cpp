#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  long long l, r, n;
  cin >> t;
  while (t--) {
    cin >> n >> l >> r;
    long long k = n / l;
    if (r * k >= n)
      cout << "Yes";
    else
      cout << "No";
    cout << "\n";
  }
  return 0;
}

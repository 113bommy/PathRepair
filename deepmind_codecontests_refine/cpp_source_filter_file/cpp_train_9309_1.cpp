#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int bo[200];
int main() {
  int t, n, l, r, k;
  cin >> t;
  while (t--) {
    cin >> n >> l >> r;
    k = n / l;
    if (r * k >= n)
      cout << "Yes";
    else
      cout << "No";
    cout << endl;
  }
  return 0;
}

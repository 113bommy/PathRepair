#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, l, r;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> l >> r;
    if ((n / l) * r >= n)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}

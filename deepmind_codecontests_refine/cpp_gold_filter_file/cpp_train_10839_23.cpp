#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  for (int i = 1; i <= t; i++) {
    long long a, b, k;
    cin >> a >> b >> k;
    cout << (a - b) * (k / 2) + a * (k % 2) << endl;
    ;
  }
  return 0;
}

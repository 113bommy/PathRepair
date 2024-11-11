#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, k, q;
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    k--;
    n--;
    cout << k + 1 + floor(k / n) << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool compare(pair<pair<long long int, long long int>, long long int> p1,
             pair<pair<long long int, long long int>, long long int> p2) {
  return p1.first.first < p2.first.first;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, n, k, i, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (c <= a) {
      cout << -1 << " " << b << "\n";
    } else if (c >= b * a) {
      if (c == b * a)
        cout << b + 1 << " " << -1 << "\n";
      else
        cout << b << " " << -1 << "\n";
    } else {
      cout << b - 1 << " " << b << "\n";
    }
  }
  return 0;
}

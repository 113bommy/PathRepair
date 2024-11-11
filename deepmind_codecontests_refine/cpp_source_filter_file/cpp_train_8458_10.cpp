#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n, p;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long int> a, b(50, 0);
    for (long long int i = 0; i < 2 * n; i++) {
      cin >> p;
      if (b[p] == 0) {
        a.push_back(p);
        b[p] = 1;
      }
    }
    for (long long int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> v;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  v = vector<long long>(n, 0);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    v[i]--;
  }
  for (long long i = 0; i < n; i++) {
    vector<bool> m(n, false);
    long long p = i;
    while (m[p] == false) {
      m[p] = true;
      p = v[i];
    }
    cout << p + 1 << " ";
  }
  return 0;
}

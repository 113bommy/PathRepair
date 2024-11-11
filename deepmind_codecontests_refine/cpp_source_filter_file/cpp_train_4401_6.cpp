#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
signed main() {
  fastio();
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    set<long long> s;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    if (s.size() >= 2)
      cout << 1;
    else
      cout << n << "\n";
  }
}

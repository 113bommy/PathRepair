#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    set<long long int> s;
    for (long long int i = 0; i < n; i++) {
      a[i] = (i + a[i]) % n;
      s.insert(a[i]);
    }
    if (s.size() == n)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, j, k, d, m, p;
    cin >> n >> k >> d;
    long long int a[n];
    m = k;
    set<long long int> s;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i <= n - d; i++) {
      for (j = i; j < i + d; j++) s.insert(a[j]);
      p = s.size();
      m = min(m, p);
      s.clear();
    }
    cout << m << endl;
  }
  return 0;
}

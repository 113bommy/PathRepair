#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
op:
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long x;
    vector<long long> a;
    vector<long long> b;
    set<long long> s;
    for (long long i = 0; i < n; i++) {
      cin >> x;
      s.insert(x);
      a.push_back(x);
    }
    for (long long i = 0; i < m; i++) {
      cin >> x;
      b.push_back(x);
    }
    long long ok = 0;
    long long ind;
    for (long long i = 0; i < m; i++) {
      if (s.find(b[i]) != s.end()) {
        ind = b[i];
        ok = 1;
        break;
      }
    }
    if (ok == 0) {
      cout << "NO" << endl;
      goto op;
    }
    cout << "YES" << endl;
    cout << 1 << " " << ind << endl;
  }
  return 0;
}

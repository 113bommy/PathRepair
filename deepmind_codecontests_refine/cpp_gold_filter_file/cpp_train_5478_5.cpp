#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, k, j, l, n, m, t;
  t = 1;
  while (t--) {
    cin >> n;
    map<long long, long long> a;
    for (i = 0; i < n; i++) {
      cin >> k;
      a[k]++;
    }
    if (a.size() != 2) {
      cout << "NO";
      return 0;
    }
    map<long long, long long>::iterator it;
    it = a.begin();
    k = it->second;
    it++;
    for (; it != a.end(); it++) {
      if (k != it->second) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES\n";
    for (it = a.begin(); it != a.end(); it++) {
      cout << it->first << " ";
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n) {
    map<int, int> k;
    map<int, int>::iterator iter;
    set<int> l;
    for (int i = 0; i < n; i++) {
      cin >> m;
      k[m] = l.size();
      l.insert(m);
    }
    long long ans = 0;
    for (iter = k.begin(); iter != k.end(); iter++) {
      ans = ans + iter->second;
    }
    cout << ans << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:5000000000")
const long long mod = 1000000007;
long long Inf = (long long)2e9;
long long LINF = (long long)1e18 + 1e17;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<bool> can(n, true);
  map<long long, set<int>> pos;
  for (int(i) = 0; (i) < n; (i)++) {
    cin >> a[i];
    pos[a[i]].insert(i);
  }
  int k = n;
  while (pos.size()) {
    if (pos.begin()->second.size() < 2) {
      pos.erase(pos.begin());
      continue;
    }
    int i1 = *pos.begin()->second.begin();
    pos.begin()->second.erase(i1);
    int i2 = *pos.begin()->second.begin();
    pos.begin()->second.erase(i2);
    long long x = pos.begin()->first;
    k--;
    can[i1] = false;
    pos[2 * x].insert(i2);
    a[i2] = 2 * x;
  }
  cout << k << endl;
  for (int(i) = 0; (i) < n; (i)++)
    if (can[i]) cout << a[i] << " ";
  return 0;
}

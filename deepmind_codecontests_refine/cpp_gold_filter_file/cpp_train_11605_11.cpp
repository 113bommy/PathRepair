#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a, m;
  cin >> a >> m;
  set<long long> s;
  while (s.find(a) == s.end()) {
    s.insert(a);
    a = (a + a % m) % m;
  }
  if (s.find(0) != s.end())
    cout << "Yes";
  else
    cout << "No";
}

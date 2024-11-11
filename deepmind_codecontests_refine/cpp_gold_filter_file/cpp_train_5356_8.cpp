#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
int main() {
  int n, p;
  cin >> p >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (s.find(x % p) != s.end()) {
      cout << i + 1;
      return 0;
    }
    s.insert(x % p);
  }
  cout << -1;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  long long n, m;
  cin >> n >> m;
  set<string> a, b;
  long long comm = 0;
  for (long long i = 0; i < n; i++) {
    string x;
    cin >> x;
    a.insert(x);
  }
  for (long long i = 0; i < m; i++) {
    string x;
    cin >> x;
    if (a.find(x) != a.end()) comm++;
    b.insert(x);
  }
  if (a.size() + (1 & comm) > b.size()) {
    cout << "YES\n";
  } else
    cout << "NO\n";
  return 0;
}

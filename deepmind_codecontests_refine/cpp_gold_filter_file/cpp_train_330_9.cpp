#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void sary(T* st, T* nd) {
  while (st < nd) cin >> *st++;
}
const long long int mod = 998244353;
void calc() {
  long long int n;
  cin >> n;
  map<long long int, long long int, greater<long long int>> ma;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    ma[x]++;
  }
  long long int g = 0, s = 0, b = 0;
  map<long long int, long long int, greater<long long int>>::iterator it =
      ma.begin();
  g = it->second;
  it++;
  while (s <= g && it != ma.end()) {
    s += it->second;
    it++;
  }
  while (it != ma.end()) {
    b += it->second;
    if (g + s + b > (n / 2)) {
      b -= it->second;
      break;
    }
    it++;
  }
  if (s > g && b > g)
    cout << g << " " << s << " " << b << "\n";
  else
    cout << 0 << " " << 0 << " " << 0 << "\n";
}
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) calc();
}

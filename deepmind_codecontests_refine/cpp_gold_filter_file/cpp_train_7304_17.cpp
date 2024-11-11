#include <bits/stdc++.h>
using namespace std;
long long int n, p, u, k;
map<long long int, long long int> b;
map<long long int, long long int>::iterator it;
long long int get(long long int n) {
  return (((n * n) % p * ((n * n) % p) + p)) % p;
}
int main() {
  cin >> n;
  cin >> p;
  cin >> k;
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> u;
    long long int s = (get(u) - (k * u) % p + 2 * p) % p;
    it = b.find(s);
    if (it != b.end()) {
      ans += it->second;
      it->second++;
    } else {
      b.insert(make_pair(s, 1));
    }
  }
  cout << ans;
}

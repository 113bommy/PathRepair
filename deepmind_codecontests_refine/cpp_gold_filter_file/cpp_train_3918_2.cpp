#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  multiset<ll> m;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m.insert(x);
  }
  if (!(m.size() & 1)) m.insert(0);
  ll S = 0;
  while (m.size() != 1) {
    ll sz = 0;
    for (int _ = 0; _ < 3; _++) {
      sz += *m.begin();
      m.erase(m.begin());
    }
    S += sz;
    m.insert(sz);
  }
  cout << S << '\n';
}

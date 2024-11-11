#include <bits/stdc++.h>
using namespace std;
using tint = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int MX = 5e5 + 5;
const tint INF = 1e18;
const int inf = 1e9;
const ld PI = acos(ld(-1));
void NACHO(string name = "stacking") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
int main() {
  NACHO();
  int n, m;
  cin >> n >> m;
  vi cities(n);
  set<int> net;
  for (int i = 0; i < int(n); i++) cin >> cities[i];
  for (int i = 0; i < int(m); i++) {
    int x;
    cin >> x;
    net.insert(x);
  }
  int ret = 0;
  for (int i = 0; i < int(n); i++) {
    auto it1 = net.lower_bound(cities[i]);
    auto it2 = it1;
    if (it1 != net.begin()) --it2;
    ret = max(ret, min((it1 == net.end() ? inf : *it1 - cities[i]),
                       (it2 == it1 ? inf : cities[i] - *it2)));
  }
  cout << ret << "\n";
}

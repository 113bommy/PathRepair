#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using edge = tuple<int, int, int, int>;
using graph = vector<vector<edge>>;
void go() {
  ll a, b;
  cin >> a >> b;
  if (a == b + 1)
    cout << "NO\n";
  else
    cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) go();
}

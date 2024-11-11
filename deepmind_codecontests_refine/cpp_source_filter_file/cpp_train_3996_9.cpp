#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 1e5 + 5;
int n, arr[N], id = 1, curh = 0, m, a, b;
void Solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  cin >> m;
  while (m--) {
    cin >> a >> b;
    if (a >= id) curh = arr[id];
    cout << curh << "\n";
    curh += b;
    while (id <= n && curh >= arr[id]) id++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 1E9 + 7;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
int n, m, k, x, y;
bool res;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  while (k--) {
    cin >> x >> y;
    if (abs(1 - x) <= 2 || abs(n - x) <= 2 || abs(1 - y) <= 2 ||
        abs(m - y) <= 2)
      res = true;
  }
  cout << (res ? "YES" : "NO") << endl;
  return 0;
}

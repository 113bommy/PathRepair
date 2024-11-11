#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> elems(n);
  for (int i = 0; i != n; ++i) {
    cin >> elems[i];
  }
  auto l = min_element(elems.rbegin(), elems.rend());
  auto h = max_element(elems.begin(), elems.end());
  int ans = distance(elems.begin(), h) + distance(elems.rbegin(), l);
  if (ans >= (n - 2)) ans--;
  cout << ans << endl;
  return 0;
}

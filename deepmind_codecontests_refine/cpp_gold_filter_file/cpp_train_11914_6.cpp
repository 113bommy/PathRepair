#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  map<int, int> last;
  int n, a, b, m;
  cin >> a >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    last[a] = 1;
  }
  for (int i = 0; i < m; ++i) {
    cin >> b;
    last[b] = 2;
  }
  for (auto pp : last) {
    cout << pp.second << " ";
  }
  return 0;
}

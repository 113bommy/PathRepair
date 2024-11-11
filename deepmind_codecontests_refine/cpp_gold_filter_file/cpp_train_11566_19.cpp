#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, maxi = 0;
  vector<int> ve;
  cin >> n;
  while (n--) {
    int k;
    cin >> k;
    if (k <= maxi) {
      ve.push_back(maxi);
      maxi = k;
      continue;
    }
    maxi = k;
  }
  ve.push_back(maxi);
  cout << (int)ve.size() << '\n';
  for (int u : ve) cout << u << ' ';
  return 0;
}

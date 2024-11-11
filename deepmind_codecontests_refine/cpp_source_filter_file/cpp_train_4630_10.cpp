#include <bits/stdc++.h>
using namespace std;
int i, k, n, w;
vector<int> t[3];
int main() {
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> k;
    t[k - 1].push_back(i + 1);
  }
  w = min(t[0].size(), min(t[1].size(), t[2].size()));
  cout << w;
  for (i = 0; i < w; ++i)
    cout << t[0][i] << ' ' << t[1][i] << ' ' << t[2][i] << endl;
  return 0;
}

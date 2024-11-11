#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1000000000")
static vector<vector<int> > vc;
int main() {
  ios_base::sync_with_stdio(0);
  int n, a, b, c;
  vector<int> res;
  cin >> n;
  vc.resize(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a;
    vc[a].push_back(i + 1);
  }
  a = 0;
  while (vc[a].size() || a > 2) {
    if (vc[a].size()) {
      res.push_back(vc[a][vc[a].size() - 1]);
      vc[a].pop_back();
      ++a;
    } else
      a -= 3;
  }
  if (res.size() < n) {
    cout << "Impossible\n";
  } else {
    cout << "possible\n";
    for (int i = 0; i < n; ++i) cout << res[i] << ' ';
  }
  return 0;
}

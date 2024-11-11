#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  char ar[n + 2];
  char br[n + 2];
  scanf("%s%s", ar + 1, br + 1);
  vector<int> v[2];
  for (int i = 1; i <= n; i++) {
    if (ar[i] != br[i]) {
      if (ar[i] == 'a')
        v[0].push_back(i);
      else
        v[1].push_back(i);
    }
  }
  if ((v[0].size() + v[1].size()) % 2 == 1)
    cout << -1 << endl;
  else {
    int res = v[0].size() + v[1].size();
    res /= 2;
    if (v[0].size() % 2) res += 1;
    cout << res << endl;
    for (int i = 1; i < v[0].size(); i += 2) {
      cout << v[0][i - 1] << " " << v[0][i] << endl;
    }
    for (int i = 1; i < v[1].size(); i += 2) {
      cout << v[1][i - 1] << " " << v[1][i] << endl;
    }
    if (v[0].size() % 2) {
      cout << v[0][v[0].size() - 1] << " " << v[0][v[1].size() - 1] << endl;
      cout << v[0][v[0].size() - 1] << " " << v[1][v[1].size() - 1] << endl;
    }
  }
  return 0;
}

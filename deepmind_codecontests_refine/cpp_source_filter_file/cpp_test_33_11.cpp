#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long ap[100005], bp[550][550];
vector<int> ve;
int main() {
  int n;
  for (int i = 0; i <= 510; i++) bp[i][0] = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ap[i];
    if (ap[i] == 0) continue;
    for (int j = 0; j < 510; j++) {
      if (!bp[ap[i]][j]) continue;
      if (bp[ap[i]][j ^ ap[i]]) continue;
      bp[ap[i]][j ^ ap[i]] = 1;
      for (int k = ap[i] + 1; k < 510; k++) {
        bp[k][j ^ ap[i]] = 1;
      }
    }
  }
  int fl = 0;
  for (int i = 0; i <= 500; i++) {
    if (bp[500][i] == 1) {
      ve.push_back(i);
    }
  }
  int len = ve.size();
  cout << len << endl;
  for (int i = 0; i < len; i++) {
    if (i != 0) cout << " ";
    cout << ve[i];
  }
  cout << endl;
}

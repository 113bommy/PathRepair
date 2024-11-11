#include <bits/stdc++.h>
using namespace std;
char a[100][100];
bool ok[100];
int main() {
  std::ios::sync_with_stdio(false);
  ;
  int n, m;
  cin >> n >> m;
  for (int(i) = (int)1; (i) <= (int)n; ++(i)) {
    for (int(j) = (int)1; (j) <= (int)n; ++(j)) {
      cin >> a[i - 1][j - 1];
    }
  }
  int res = 0;
  for (int(i) = (int)1; (i) <= (int)m; ++(i)) {
    bool no = 0;
    for (int(j) = (int)1; (j) <= (int)n - 1; ++(j)) {
      if (a[j - 1][i - 1] > a[j][i - 1] && !ok[j - 1]) no = 1;
    }
    res += no;
    if (!no) {
      for (int(j) = (int)1; (j) <= (int)n; ++(j)) {
        if (a[j - 1][i - 1] < a[j][i - 1]) ok[j - 1] = 1;
      }
    }
  }
  cout << res << endl;
}

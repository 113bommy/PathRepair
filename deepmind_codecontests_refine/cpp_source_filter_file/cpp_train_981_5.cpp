#include <bits/stdc++.h>
using namespace std;
char a[2000][2000];
int main() {
  int n, m, k, i, j, cnt;
  vector<int> v;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) {
    cnt = 0;
    for (j = 0; j < n; j++) {
      if (i - j >= 0 && a[j][i - j] == 'R') cnt++;
      if (i + j < m && a[j][i + j] == 'L') cnt++;
      if (a[j][i] == 'U' && j >= 2) cnt++;
      if (a[0][0] == 'D') cnt++;
    }
    v.push_back(cnt);
  }
  for (i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
  return 0;
}

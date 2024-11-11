#include <bits/stdc++.h>
using namespace std;
int n, m;
char d[1000][1000];
int main() {
  cin >> n >> m;
  gets(d[500]);
  for (int i = 0; i < n; ++i) {
    gets(d[i]);
  }
  long long ans = 0;
  for (int j = 0; j < m; ++j) {
    set<char> tmp;
    for (int i = 0; i < n; ++i) {
      tmp.insert(d[i][j]);
    }
    if (j == 0)
      ans += tmp.size();
    else
      ans = (ans * tmp.size()) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}

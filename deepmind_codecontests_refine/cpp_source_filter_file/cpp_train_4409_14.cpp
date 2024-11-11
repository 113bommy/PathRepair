#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0;
char ch[110][110];
int main() {
  cin >> n >> m;
  for (register int i = (1); i <= (n); ++i) {
    for (register int j = (1); j <= (m); ++j)
      cin >> ch[i][j], cnt += ch[i][j] == '*' ? 1 : 0;
    if (cnt == 2) cnt = 0;
    if (cnt == 1) cout << i << ' ', cnt = 0;
  }
  for (register int i = (1); i <= (m); ++i) {
    for (register int j = (1); j <= (n); ++j) cnt += ch[j][i] == '*' ? 1 : 0;
    if (cnt == 2) cnt = 0;
    if (cnt == 1) cout << i << endl;
  }
  return 0;
}

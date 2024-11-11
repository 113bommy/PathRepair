#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, p[1000], b[1000], s[1000], e[1000];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    b[i] = p[i];
  }
  sort(p, p + n);
  for (int i = 0; i < m; i++) cin >> s[i] >> e[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (p[j] == b[i]) cout << j % 2 << endl;
  return 0;
}

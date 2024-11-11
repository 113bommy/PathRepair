#include <bits/stdc++.h>
using namespace std;
string a[37], b[37];
int ans;
int n, q;
void dfs(string ss) {
  if (ss.size() == q) {
    ans++;
    return;
  }
  for (int i = 1; i <= q; i++) {
    if (ss[0] == b[i][0]) dfs(a[i] + ss.substr(1));
  }
}
int main() {
  while (scanf("%d %d", &n, &q) != EOF) {
    for (int i = 1; i <= q; i++) {
      cin >> a[i] >> b[i];
    }
    ans = 0;
    dfs("a");
    printf("%d\n", ans);
  }
  return 0;
}

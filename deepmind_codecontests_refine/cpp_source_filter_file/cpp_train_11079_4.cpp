#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, sum, p[110], q[110];
  while (cin >> n) {
    sum = 0;
    for (i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    memset(q, 0, sizeof(q));
    for (i = 0; i < n; i++)
      if (!q[i]) {
        sum++;
        int ans = 0;
        for (j = i + 1; j < n; j++) {
          if (q[j]) continue;
          if (p[j] >= ans) {
            q[j] = 1;
            ans++;
          }
        }
      }
    cout << sum << endl;
  }
}

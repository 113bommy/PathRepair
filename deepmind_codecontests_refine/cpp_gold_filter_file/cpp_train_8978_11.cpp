#include <bits/stdc++.h>
using namespace std;
int t, n, head, c;
int a[4005];
vector<int> q;
int p[4005][2005];
int main(void) {
  cin >> t;
  while (t--) {
    cin >> n;
    head = -1;
    c = 0;
    q.clear();
    for (int i = 0; i < 2 * n; i++) {
      cin >> a[i];
      if (head < a[i]) {
        if (head != -1) q.push_back(c);
        head = a[i];
        c = 1;
      } else
        c++;
    }
    if (c) q.push_back(c);
    for (int i = 0; i < q.size(); i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0) {
          if (j < q[i])
            p[i][j] = 0;
          else
            p[i][j] = q[i];
          continue;
        }
        if (j == 0) {
          p[i][j] = 0;
          continue;
        }
        int q1, q2;
        if (q[i] > j) {
          p[i][j] = p[i - 1][j];
        } else {
          q1 = q[i] + p[i - 1][j - q[i]];
          q2 = p[i - 1][j];
          p[i][j] = max(q1, q2);
        }
      }
    }
    if (p[q.size() - 1][n] == n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

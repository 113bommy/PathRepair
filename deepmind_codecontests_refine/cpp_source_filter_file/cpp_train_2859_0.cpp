#include <bits/stdc++.h>
using namespace std;
int n, m, q, ans;
char s[2005][2005];
int x[2005], y[2005], ret[2005], f[2005][2005], l[2005][2005], r[2005][2005];
bool check(int L, int y) {
  deque<int> q1, q2;
  for (int i = 1; i <= n; i++) {
    for (; !q1.empty() && l[q1.back()][y] <= l[i][y]; q1.pop_back())
      ;
    for (; !q2.empty() && r[q2.back()][y] >= r[i][y]; q2.pop_back())
      ;
    for (; !q1.empty() && q1.front() <= i - L; q1.pop_front())
      ;
    for (; !q2.empty() && q2.front() <= i - L; q2.pop_front())
      ;
    q1.push_back(i), q2.push_back(i);
    if (i >= L && r[q2.front()][y] - l[q1.front()][y] + 1 >= L) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x[i], &y[i]);
    x[i]--, y[i]--;
    s[x[i]][y[i]] = 'X';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.')
        f[i][j] = min(min(i ? f[i - 1][j] : 0, j ? f[i][j - 1] : 0),
                      (i && j) ? f[i - 1][j - 1] : 0) +
                  1,
        l[i][j] = j ? l[i][j - 1] : 0;
      else
        l[i][j] = j + 1;
      ans = max(ans, f[i][j]);
    }
    for (int j = m - 1; j >= 0; j--)
      if (s[i][j] == '.')
        r[i][j] = j + 1 < m ? r[i][j + 1] : m - 1;
      else
        r[i][j] = j - 1;
  }
  ret[q] = ans;
  for (int i = q; i >= 1;) {
    s[x[i]][y[i]] = '.';
    for (int j = 0; j < m; j++)
      if (s[x[i]][j] == '.')
        l[x[i]][j] = j ? l[x[i]][j - 1] : 0;
      else
        l[x[i]][j] = j + 1;
    for (int j = m - 1; j >= 0; j--)
      if (s[x[i]][j] == '.')
        r[x[i]][j] = j + 1 < m ? r[x[i]][j + 1] : m - 1;
      else
        r[x[i]][j] = j - 1;
    for (; check(ans + 1, y[i]); ans++)
      ;
    ret[--i] = ans;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ret[i]);
}

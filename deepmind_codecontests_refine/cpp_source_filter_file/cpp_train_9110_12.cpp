#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, m, s, d, step = 0, pos = 0;
  bool flg = true;
  cin >> n >> m >> s >> d;
  vector<int> p(n);
  vector<int> plan(2 * n);
  for (i = 0; i < n; i++) cin >> p[i];
  for (i = 0; i < 2 * n; i++) plan[i] = 0;
  sort(p.begin(), p.end());
  i = 0;
  while (i < n) {
    plan[step] = p[i] - 1 - pos;
    if (plan[step] == 0) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    pos += plan[step];
    step++;
    i++;
    while (i < n && p[i] - p[i - 1] < s + 2) i++;
    plan[step] = p[i - 1] + 1 - pos;
    if (plan[step] > d) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    pos += plan[step];
    step++;
  }
  if (pos < m) plan[step] = m - pos;
  i = 0;
  while (plan[i] > 0) {
    if (i % 2 == 1 && plan[i] > d) flg = false;
    i++;
  }
  if (flg) {
    i = 0;
    while (i < 2 * n && plan[i] > 0) {
      if (i % 2 == 0)
        cout << "RUN " << plan[i] << endl;
      else
        cout << "JUMP " << plan[i] << endl;
      i++;
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}

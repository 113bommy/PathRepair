#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323846;
const int inf = (int)1e9;
const long double eps = 1e-9;
const int N = 2e5 + 5;
int n, m, s, d;
int a[N];
int main() {
  scanf("%d %d %d %d", &n, &m, &s, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  if (a[0] - 1 < s) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  int d1 = d - 1;
  for (int i = d1; i < n; ++i) {
    if (a[i - d1] == a[i] - d1) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  vector<int> res;
  vector<char> moves;
  int lastCan = a[0] - 1;
  res.push_back(lastCan);
  moves.push_back('R');
  for (int i = 1; i < n; ++i) {
    if (a[i] - a[i - 1] - 2 < s) {
      continue;
    }
    int jump = a[i - 1] + 1 - lastCan;
    if (jump > d) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    res.push_back(jump);
    moves.push_back('J');
    lastCan = a[i] - 1;
    res.push_back((a[i] - 1) - (a[i - 1] + 1));
    moves.push_back('R');
  }
  int jump = a[n - 1] + 1 - lastCan;
  if (jump > d) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  res.push_back(jump);
  moves.push_back('J');
  if (m - (a[n - 1] + 1) > 0) {
    res.push_back(m - (a[n - 1] + 1));
    moves.push_back('R');
  }
  for (int i = 0; i < res.size(); ++i) {
    if (moves[i] == 'R') {
      cout << "RUN " << res[i] << "\n";
    } else {
      cout << "JUMP " << res[i] << "\n";
    }
  }
  return 0;
}

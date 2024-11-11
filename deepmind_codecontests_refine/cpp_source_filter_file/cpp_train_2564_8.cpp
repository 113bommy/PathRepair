#include <bits/stdc++.h>
using namespace std;
const int N = 205;
deque<int> p[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  p[0] = {1};
  p[1] = {0, 1};
  for (int i = 2; i <= n; ++i) {
    p[i] = p[i - 1];
    p[i].push_front(0);
    int failed = 0;
    for (int j = 0; j < (((int)(p[i - 2]).size())); ++j)
      if (abs(p[i - 2][j] + p[i][j]) > 1) {
        failed |= 1;
        break;
      }
    if (~failed & 1) {
      for (int j = 0; j < (((int)(p[i - 2]).size())); ++j)
        p[i][j] += p[i - 2][j];
      continue;
    }
    for (int j = 0; j < (((int)(p[i - 2]).size())); ++j)
      if (abs(p[i - 2][j] - p[i][j]) > 1) {
        failed |= 2;
        break;
      }
    if (~failed & 2) {
      for (int j = 0; j < (((int)(p[i - 2]).size())); ++j)
        p[i][j] -= p[i - 2][j];
      continue;
    }
    return 0;
  }
  cout << ((int)(p[n]).size()) << '\n';
  for (int i = 0; i < (((int)(p[n]).size())); ++i) cout << p[n][i] << ' ';
  cout << '\n';
  cout << ((int)(p[n - 1]).size()) << '\n';
  for (int i = 0; i < (((int)(p[n - 1]).size())); ++i)
    cout << p[n - 1][i] << ' ';
  cout << '\n';
  return 0;
}

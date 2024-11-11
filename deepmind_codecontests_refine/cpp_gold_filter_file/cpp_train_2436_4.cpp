#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
void f(long long int& x, long long int& y, char c) {
  switch (c) {
    case 'U':
      y++;
      break;
    case 'D':
      y--;
      break;
    case 'R':
      x++;
      break;
    case 'L':
      x--;
      break;
  };
}
void r(long long int& x, long long int& y, char c) {
  switch (c) {
    case 'U':
      y--;
      break;
    case 'D':
      y++;
      break;
    case 'R':
      x--;
      break;
    case 'L':
      x++;
      break;
  };
}
int main() {
  ios_base::sync_with_stdio(false);
  long long int a, b;
  string s;
  cin >> a >> b >> s;
  bool q = !a && !b;
  long long int len = s.size();
  for (int i = 0; i < len && !q; i++) {
    long long int x[2] = {a, a}, y[2] = {b, b}, d[2];
    for (int j = i; j < len; j++) f(x[0], y[0], s[j]);
    for (int j = i - 1; j >= 0; j--) r(x[1], y[1], s[j]);
    d[0] = x[0] - x[1];
    d[1] = y[0] - y[1];
    if (!d[0] && !d[1]) {
      q = !x[1] && !y[1];
      continue;
    }
    if (!d[0]) q = x[0] == 0 && y[0] % d[1] == 0 && y[0] / d[1] > 0;
    if (!d[1]) q = y[0] == 0 && x[0] % d[0] == 0 && x[0] / d[0] > 0;
    if (d[0] && d[1])
      q = x[0] % d[0] == 0 && y[0] % d[1] == 0 && x[0] / d[0] == y[0] / d[1] &&
          x[0] / d[0] > 0;
  }
  if (q)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

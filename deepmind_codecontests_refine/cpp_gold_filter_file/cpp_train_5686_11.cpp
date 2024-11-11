#include <bits/stdc++.h>
using namespace std;
int a, b, c, n, i;
bool fl;
pair<int, int> x[200000];
int main() {
  a = -1;
  b = -1;
  cin >> n;
  for (i = 0; i < n; i++) cin >> x[i].first >> x[i].second;
  sort(x, x + n);
  for (i = 0; i < n; i++) {
    if (a < x[i].first)
      a = x[i].second;
    else if (b < x[i].first)
      b = x[i].second;
    else {
      cout << "NO";
      fl = 1;
      break;
    }
  }
  if (fl == 0) cout << "YES";
  return 0;
}

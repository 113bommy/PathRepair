#include <bits/stdc++.h>
using namespace std;
vector<long long> stiva;
long long ans, n, i, j, x[200010], valleft[200010], valright[200010],
    lft[200010][40], rgt[200010][40];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> x[i];
  for (i = 1; i <= n; i++)
    for (j = 0; j <= 30; j++)
      if (x[i - 1] & (1 << j))
        lft[i][j] = i - 1;
      else
        lft[i][j] = lft[i - 1][j];
  for (j = 0; j <= 30; j++) rgt[n + 1][j] = n + 1;
  for (i = n; i >= 1; i--)
    for (j = 0; j <= 30; j++)
      if (x[i + 1] & (1 << j))
        rgt[i][j] = i + 1;
      else
        rgt[i][j] = rgt[i + 1][j];
  for (i = 1; i <= n; i++) {
    while (stiva.size() && (x[stiva.back()] < x[i])) stiva.pop_back();
    if (stiva.size())
      valleft[i] = stiva.back();
    else
      valleft[i] = 0;
    stiva.push_back(i);
  }
  stiva.resize(0);
  for (i = n; i >= 1; i--) {
    while (stiva.size() && (x[stiva.back()] < x[i])) stiva.pop_back();
    if (stiva.size())
      valright[i] = stiva.back();
    else
      valright[i] = n + 1;
    stiva.push_back(i);
  }
  for (i = 1; i <= n; i++) {
    long long varx = valleft[i], vary = valright[i];
    long long X = varx, Y = vary;
    for (j = 0; j <= 30; j++)
      if (!(x[i] & (1 << j))) {
        varx = max(varx, lft[i][j]);
        vary = min(vary, rgt[i][j]);
      }
    ans += (i - X) * (Y - i) - (i - varx) * (vary - i);
  }
  cout << ans;
  return 0;
}

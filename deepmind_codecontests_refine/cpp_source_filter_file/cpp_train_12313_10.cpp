#include <bits/stdc++.h>
int const N = 1e6 + 5, M = 205;
using namespace std;
long long row[N], a, x, y, ans = -1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  row[0] = 1, row[1] = 2;
  for (int i = 2; i < N; i++) row[i] = row[i - 1] + (i % 2 ? 1 : 2);
  cin >> a >> x >> y;
  long long pos = y / a;
  if ((!pos || pos & 1) && abs(x) < a / 2.0)
    ans = row[pos];
  else if (pos && !(pos & 1) && x && abs(x) < a)
    ans = (x < 0 ? row[pos] : row[pos] + 1);
  if (y % a == 0) ans = -1;
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
pair<int, int> bb[4];
int n, a, b, c;
int main() {
  cin >> n >> a >> b >> c;
  if (a < b)
    bb[1] = {2, a};
  else
    bb[1] = {3, b};
  if (a < c)
    bb[2] = {1, a};
  else
    bb[2] = {3, c};
  if (b < c)
    bb[3] = {1, b};
  else
    bb[3] = {2, c};
  long long x = 1, ans = 0;
  for (int i = 2; i <= n; i++) {
    ans += bb[x].second;
    x = bb[x].first;
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long maxi = max(b - c, a - d);
  long long mini = min(b - c, a - d);
  long long minx, maxx;
  if (mini < 0)
    minx = 0 - mini;
  else
    minx = 1;
  if (maxi < 0)
    maxx = n;
  else
    maxx = n - maxi;
  long long count = 0;
  for (int i = minx; i <= maxx; i++)
    if (a + b - c - d + i <= n && a + b - c - d + i >= 1) count++;
  if (maxx < minx) {
    cout << 0 << endl;
    return 0;
  }
  cout << n * (count) << endl;
  return 0;
}

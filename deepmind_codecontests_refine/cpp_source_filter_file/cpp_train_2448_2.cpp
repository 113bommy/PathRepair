#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int com[200005], az = a.size(), bz = b.size();
  long long res = 0;
  com[0] = 0;
  for (int i = 0; i < az; i++) com[i + 1] = com[i] + a[i] - '0';
  for (int i = 0; i < bz; i++) {
    int y = min(az, i + 1), x = max(az - (bz - i), 0);
    if (b[i] == '0')
      res += com[y] - com[x];
    else
      res += (y - x) - com[y] - com[x];
  }
  cout << res;
}

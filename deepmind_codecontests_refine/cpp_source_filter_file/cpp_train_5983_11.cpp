#include <bits/stdc++.h>
using namespace std;
int n, p;
string s;
vector<int> fix;
int tot = 0;
int um(int x, int y, int z) {
  if (y <= x && x <= z)
    return z - y + min(x - y, z - x);
  else
    return max(abs(x - z), abs(y - z));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> p >> s;
  for (int i = 0; 2 * i < n; i++) {
    int d = abs(s[i] - s[n - 1 - i]);
    tot += min(d, 26 - d);
    if (d == 0) fix.push_back(i);
  }
  if ((int)fix.size() != 0) {
    int lo = fix[0];
    int hi = fix[(int)fix.size() - 1];
    tot += min(um(p, lo, hi), um(p, n - 1 - hi, n - 1 - lo));
  }
  printf("%d\n", tot);
}

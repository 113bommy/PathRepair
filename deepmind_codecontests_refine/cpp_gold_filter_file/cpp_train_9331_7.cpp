#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long j, s, zh, z, si;
  cin >> j >> s >> zh >> z >> si;
  long long res = 0;
  if ((zh * 2 + z - j) > 0) res += zh * 2 + z - j;
  if ((si * 3 + z - s) > 0) res += (si * 3 + z - s);
  cout << res;
  return 0;
}

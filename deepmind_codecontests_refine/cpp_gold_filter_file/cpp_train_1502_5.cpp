#include <bits/stdc++.h>
using namespace std;
long long b, s, c;
long long nb, ns, nc;
long long pb, ps, pc;
long long money;
string str;
bool check(long long x) {
  long long cb = max((b * x - nb) * pb, 0 * 1ll);
  long long cs = max((s * x - ns) * ps, 0 * 1ll);
  long long cc = max((c * x - nc) * pc, 0 * 1ll);
  if (cb + cs + cc <= money) return true;
  return false;
}
int main() {
  cin >> str;
  for (long long i = 0; i < str.size(); i++) {
    if (str[i] == 'B')
      b++;
    else if (str[i] == 'S')
      s++;
    else if (str[i] == 'C')
      c++;
  }
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> money;
  long long l = 0, r = 2e12;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      l = mid + 1;
    else
      r = mid;
  }
  cout << l - 1 << endl;
  return 0;
}

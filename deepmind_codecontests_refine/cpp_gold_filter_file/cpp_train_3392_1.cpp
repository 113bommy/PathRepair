#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int N = 1e5 + 5;
const long long M = 1e12 + 12;
map<long long, int> m, s;
bool go(int total) {
  long long at = 1;
  int sobra = m[1] - total;
  if (sobra < 0) return false;
  at <<= 1;
  while (at < 2LL * M) {
    sobra += s[at];
    sobra += m[at] - total;
    sobra = max(sobra, 0);
    total = min(total, m[at]);
    at <<= 1;
  }
  return !sobra;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    long long a;
    cin >> a;
    m[a]++;
    bool f = 0;
    int y = 0;
    while (a != 1) {
      if (a % 2) f = 1;
      a >>= 1;
      y++;
    }
    if (f) {
      y++;
      while (y--) a <<= 1;
      s[a]++;
    }
  }
  bool f = 0;
  for (int i = 1; i < N; i++)
    if (go(i)) {
      f = 1;
      cout << i << " ";
    }
  if (!f) cout << -1;
  cout << endl;
  return 0;
}

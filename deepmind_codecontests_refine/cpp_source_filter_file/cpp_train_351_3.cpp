#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100000;
const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int n, a, s, amax, rs;
int main() {
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> a;
    amax = (((a) > (amax)) ? (a) : (amax));
    s += a;
  }
  rs = amax;
  a = amax * (1 - n) + s;
  if (a > 0) {
    rs += a / (n - 1);
    a = a % (n - 1);
    if (a % n != 0) rs++;
  }
  cout << rs;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k;
char ans[100];
bool check(int x, int y) {
  if (y == -1) return 1;
  cout << 1 << " " << x << " " << y << endl;
  cin >> ans;
  return ans[0] == 'T';
}
int query(int l, int r) {
  int m;
  if (l > r) return -1;
  while (l < r) {
    m = (l + r) >> 1;
    if (check(m, m + 1))
      r = m;
    else
      l = m + 1;
  }
  return l;
}
int main() {
  cin >> n >> k;
  int f = query(1, n);
  int s = query(1, f - 1);
  if (check(f, s)) s = query(f + 1, n);
  cout << 2 << " " << f << " " << s << endl;
  fflush(stdout);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  cout.sync_with_stdio(false);
  cin.tie(nullptr);
  string a, b, c, d;
  cin >> a >> b >> c >> d;
  reverse(b.begin(), b.end());
  reverse(d.begin(), d.end());
  string x = a + b, y = c + d;
  string xx = x;
  bool flag = false;
  int k, kk;
  for (int i = 0; i < 4; ++i)
    if (x[i] == 'X') k = i;
  kk = k;
  for (int i = 0; i < 50; ++i) {
    if (x == y || xx == y) flag = true;
    int f = (k + 1) % 4;
    int g = kk - 1 < 0 ? 3 : kk - 1;
    swap(x[k], x[f]);
    swap(xx[kk], xx[g]);
    k = f;
    kk = g;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

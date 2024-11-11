#include <bits/stdc++.h>
using namespace std;
const int N = 3000 * 1000 * 100 + 3;
int l, r, ans;
bitset<N> b;
void qrbal() {
  int i = 2;
  b.set(1);
  if (l == r && r == 2) ans = 1;
  for (i = 2; i * i < r + 1; i++)
    if (b[i] == false) {
      for (int j = i * i; j < r + 1; j += i) b.set(j);
      if ((i % 4 == 1) && i >= l) ans++;
    }
  for (i = max(i, l); i < r + 1; i++)
    if (i % 4 == 1 && b[i] == false) ans++;
}
int main() {
  ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
  cin >> l >> r;
  qrbal();
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int mallow(int e) {
  if (e % 2 == 1) return e * (e - 1) / 2 + 1;
  return e * (e - 1) / 2 + 1 + max((e - 3), 0);
}
int main() {
  int n, m, p, w[100000], sz;
  long long sum = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> p >> w[i];
  sort(w, w + m);
  reverse(w, w + m);
  for (sz = 1; mallow(sz) <= n && sz <= m; sz++)
    ;
  sz--;
  for (int i = 0; i < sz; i++) sum += w[i];
  cout << sum << '\n';
  return 0;
}

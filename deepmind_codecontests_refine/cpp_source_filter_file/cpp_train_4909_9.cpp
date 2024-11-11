#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e8 + 1;
bitset<MAXN> b;
int main() {
  ios::sync_with_stdio(false);
  int ans = 0;
  int l, r;
  cin >> l >> r;
  for (int i = 3; i * i < r; i += 2)
    if (!b[i])
      for (int j = i * i; j < r; j += i) b[j] = 1;
  for (int i = 5; i <= r; i += 4)
    if (!b[i] and i >= l) ans++;
  if (2 <= r and 2 >= l) ans++;
  cout << ans << endl;
  return 0;
}

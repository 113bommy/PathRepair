#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
int a[50], b[50];
ll power(int x, int y) {
  ll res = 1;
  while (y--) res = res * 2;
  return res;
}
int main() {
  ll s, x;
  cin >> s >> x;
  if (x == 0) return cout << !(s % 2), 0;
  int ts = 0;
  if (s == x) ts = 2;
  ll r = x, pos = 0;
  while (r) {
    a[pos++] = r % 2;
    r /= 2;
  }
  ll dif = s - x;
  if (dif % 2 == 1) return cout << 0, 0;
  dif /= 2;
  ll ans = 0;
  pos = 0;
  while (dif) {
    b[pos++] = dif % 2;
    dif /= 2;
  }
  for (int i = 0; i < 50; i++) {
    if (a[i] && b[i]) return cout << 0, 0;
  }
  while (x) {
    ans += x % 2;
    x = x / 2;
  }
  cout << power(2, ans) - ts << endl;
  return 0;
}

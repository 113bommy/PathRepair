#include <bits/stdc++.h>
using namespace std;
inline void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void ld(int n, long long int a[]) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
void solve() {
  long long int s, x;
  cin >> s >> x;
  if (x > s) {
    cout << 0 << "\n";
    return;
  }
  if (x % 2 != s % 2) {
    cout << 0 << "\n";
    return;
  }
  long long int ct = 0;
  long long int s1 = s;
  while (s1 > 0) {
    s1 = s1 / 2;
    ct++;
  }
  if (s != x) ct--;
  long long int x1 = x;
  long long int ct1 = 0;
  long long int ab = (s - x) / 2;
  long long int ans = 1;
  for (long long int i = 0; i < 62; i++) {
    long long int sab = (ab >> i) & 1LL;
    long long int sx = (x >> i) & 1LL;
    long long int sss = (s >> i) & 1LL;
    if (sab == 1 && sx == 1) {
      cout << 0 << "\n";
      return;
    }
    if (sab == 1)
      ans = ans * 1LL;
    else {
      if (sx == 1) ans = ans * 2LL;
    }
  }
  if (s == x) ans -= 2;
  cout << ans;
}
int main() {
  fast();
  solve();
}

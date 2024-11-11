#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1e5;
int n, m, t, a[maxn], b[maxn], ans;
bool can(int num, int k) {
  if (num % 2 == 0 or k < 0) return 0;
  if (k <= 1) return k ^ (!(num & (num + 1)));
  if (num == 9 && k == 2) return 0;
  return 2 * k + 3 <= num;
}
void did(int num, int k, int from) {
  int now = ++t;
  cout << from << " ";
  for (int i = 1; i <= num - 1; i = 2 * i + 1) {
    int other = num - i - 1, otherk = k - (max(other, i) >= 2 * min(other, i));
    if (can(i, 0) && can(other, otherk)) {
      did(i, 0, now), did(other, otherk, now);
      return;
    }
  }
}
void solve() {
  cin >> n >> m;
  if (!can(n, m))
    cout << "NO";
  else {
    cout << "YES\n";
    did(n, m, 0);
    cout << "\n";
  }
  return;
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}

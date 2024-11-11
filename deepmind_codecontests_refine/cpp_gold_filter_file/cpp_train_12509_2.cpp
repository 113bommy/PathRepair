#include <bits/stdc++.h>
using namespace std;
const int maxn = 500100;
const int INF = (1LL << 29);
int n, a[maxn];
int v[6];
int b[6] = {4, 8, 15, 16, 23, 42};
int c[6] = {1, 2, 3, 4, 5, 0};
int id(int x) {
  for (int i = 0; i <= 5; i++)
    if (b[i] == x) return i;
  return -1;
}
void solve() {
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(v, 0, sizeof(v));
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 4)
      v[0]++;
    else {
      int x = id(a[i]);
      if (x == -1)
        cnt++;
      else if (v[x - 1] == 0)
        cnt++;
      else
        v[x - 1]--, v[x]++;
    }
  }
  int res = cnt;
  for (int i = 0; i <= 4; i++) res += v[i] * c[i];
  cout << res << endl;
}
int main() {
  while (cin >> n) solve();
  return 0;
}

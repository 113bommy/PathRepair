#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool mini(T &x, T y) {
  if (x > y)
    x = y;
  else
    return 0;
  return 1;
}
const int N = 1e5 + 5;
int n, m;
int a[N];
int cnt[21][21];
int f[1 << 20];
int pop[1 << 20];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    a[i] = c - 'a';
  }
  for (int i = 1; i <= n - 1; ++i)
    if (a[i] != a[i + 1]) {
      ++cnt[a[i]][a[i + 1]];
      ++cnt[a[i + 1]][a[i]];
    }
  int ma = (1 << m) - 1;
  for (int i = 1; i <= ma; ++i) pop[i] = 1 + pop[i & (i - 1)];
  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  for (int mask = 1; mask <= ma; ++mask) {
    for (int i = 0; i <= m - 1; ++i)
      if ((((mask) >> (i)) & 1)) {
        int pmask = mask ^ (1 << i);
        int pos = pop[mask];
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j <= m - 1; ++j) {
          if ((((pmask) >> (j)) & 1))
            cnt1 += cnt[i][j];
          else
            cnt2 += cnt[i][j];
        }
        mini(f[mask], f[pmask] + pos * (cnt1 - cnt2));
      }
  }
  cout << f[ma];
  return 0;
}

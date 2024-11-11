#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int n, m;
const int mod = 1e9 + 7;
void add(int &a, int b) { a = (a + b) < mod ? a + b : a + b - mod; }
vector<int> ff[5100];
int s[5100];
int a[5100], b[5100];
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) s[i] = read();
  for (int i = 1; i <= m; ++i) {
    int col = read(), h = read();
    int tmph = h;
    for (int j = 1; j <= n; ++j)
      if (s[j] == col) {
        --h;
        if (!h) {
          a[i] = j;
          break;
        }
      }
    h = tmph;
    for (int j = n; j; --j)
      if (s[j] == col) {
        --h;
        if (!h) {
          b[i] = j;
          break;
        }
      }
    if (!h) ff[col].push_back(i);
  }
  int mx = 0, ans = 1;
  for (int i = 1; i <= n; ++i) {
    mx += (bool)ff[i].size();
    ans = 1ll * ans * max(1, (int)ff[i].size());
  }
  for (int i = 1; i <= n; ++i) {
    int nmx = 0, nans = 1;
    bool flag = false;
    int cnt = 0;
    for (int j = 0; j < ff[s[i]].size(); ++j) {
      int x = ff[s[i]][j];
      if (a[x] == i)
        flag = true;
      else if (b[x] > i)
        ++cnt;
    }
    if (!flag) continue;
    nmx = flag + (bool)cnt;
    if (cnt) nans = 1ll * nans * cnt % mod;
    for (int k = 1; k <= n; ++k) {
      if (k == s[i]) continue;
      int n1 = 0, n2 = 0, n3 = 0;
      for (int j = 0; j < ff[k].size(); ++j) {
        int x = ff[k][j];
        if (a[x] < i && b[x] > i)
          ++n3;
        else if (a[x] < i)
          ++n1;
        else if (b[x] > i)
          ++n2;
      }
      int ways = 0;
      add(ways, n3 * (n3 - 1) % mod);
      add(ways, n1 * n2 % mod);
      add(ways, n2 * n3 % mod);
      add(ways, n1 * n3 % mod);
      if (ways) {
        nmx += 2;
        nans = 1ll * nans * ways % mod;
        continue;
      }
      ways = (n1 + n2 + n3 * 2) % mod;
      if (ways) {
        ++nmx;
        nans = 1ll * ways * nans % mod;
        continue;
      }
    }
    if (nmx == mx) {
      add(ans, nans);
    } else if (nmx > mx) {
      ans = nans;
      mx = nmx;
    }
  }
  cout << mx << " " << ans << endl;
  return 0;
}

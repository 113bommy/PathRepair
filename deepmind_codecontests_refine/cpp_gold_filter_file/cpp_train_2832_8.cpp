#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int q, n;
char s[2][200010], ts[2][200010];
int c[30];
int Lowbit(int x) { return x & (-x); }
void Update(int x, int d) {
  while (x <= 29) {
    c[x] += d;
    x += Lowbit(x);
  }
}
int Getsum(int x) {
  int res = 0;
  while (x) {
    res += c[x];
    x -= Lowbit(x);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> q;
  for (int t = 1; t <= q; ++t) {
    cin >> n;
    cin >> s[0] >> s[1];
    memcpy(ts, s, sizeof(s));
    for (int i = 0; i <= 1; ++i) sort(ts[i], ts[i] + n);
    bool f = true;
    for (int i = 0; i <= n - 1; ++i)
      if (ts[0][i] != ts[1][i]) {
        f = false;
        break;
      }
    if (f) {
      bool ff = false;
      for (int i = 0; i <= n - 2; ++i)
        if (ts[0][i] == ts[0][i + 1]) {
          ff = true;
          break;
        }
      if (!ff) {
        int cnt[2] = {0};
        for (int i = 0; i <= 1; ++i) {
          memset(c, 0, sizeof(c));
          for (int j = n - 1; j >= 0; --j) {
            int id = s[i][j] - 'a' + 1;
            cnt[i] += Getsum(id - 1);
            Update(id, 1);
          }
        }
        if (abs(cnt[0] - cnt[1]) % 2) f = false;
      }
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

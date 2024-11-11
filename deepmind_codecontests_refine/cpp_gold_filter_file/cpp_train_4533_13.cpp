#include <bits/stdc++.h>
using namespace std;
const int PS = 13;
string s[30];
int a[101010];
int cnt[PS + 1][(1 << (20 - PS))];
int pc[(1 << PS)];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < (1 << PS); i++) {
    pc[i] = __builtin_popcount(i);
  }
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (s[j][i] == '1') {
        a[i] |= (1 << j);
      }
    }
  }
  int p1 = min(PS, n);
  int p2 = n - p1;
  int v = n * m;
  for (int b = 0; b < (1 << p1); b++) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; i++) {
      int t = (a[i] ^ b) & ((1 << p1) - 1);
      cnt[pc[t]][a[i] >> p1]++;
    }
    for (int b2 = 0; b2 < (1 << p2); b2++) {
      int t = 0;
      for (int j = 0; j <= p1; j++) {
        for (int bb = 0; bb < (1 << p2); bb++) {
          int tt = (j + pc[bb ^ b2]);
          t += cnt[j][bb] * min(tt, n - tt);
        }
      }
      v = min(v, t);
    }
  }
  cout << v << endl;
}

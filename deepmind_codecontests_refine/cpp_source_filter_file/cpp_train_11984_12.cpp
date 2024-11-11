#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 350;
const long long PHI = (long long)998244352;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = (long long)998244353;
const long long OVER_FLOW = 0x7fffffff;
const long long LOVER_FLOW = 0x7fffffffffffffff;
long long n;
struct op {
  long long x1, y1, x2, y2;
};
long long vis[MAXN][MAXN];
vector<op> res;
string str;
void add(long long x1, long long y1, long long x2, long long y2) {
  res.push_back((op){x1, y1, x2, y2});
  vis[x2][y2]++;
}
void move(long long x1, long long y1, bool x) {
  if (x) {
    if (x1 != 1) {
      add(x1, y1, 1, y1);
    } else {
      add(x1, y1, 1, y1 == 1 ? 2 : 1);
    }
  } else {
    if (x1 != 2) {
      add(x1, y1, 2, y1);
    } else {
      add(x1, y1, 2, y1 == 1 ? 2 : 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  long long m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> str;
      for (long long k = str.size() - 1; k >= 0; k--) {
        move(i, j, str[k] == '1');
      }
    }
  }
  for (long long i = 1; i <= 2; i++) {
    for (long long j = 2; j <= m; j++) {
      while (vis[i][j]) {
        add(i, j, i, 1);
        vis[i][j]--;
      }
    }
  }
  long long cnt = res.size();
  memset(vis, 0, sizeof vis);
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> str;
      for (auto k : str) {
        move(i, j, k == '1');
      }
    }
  }
  for (long long i = 1; i <= 2; i++) {
    for (long long j = 2; j <= m; j++) {
      while (vis[i][j]) {
        add(i, j, i, 1);
        vis[i][j]--;
      }
    }
  }
  cout << res.size() << '\n';
  for (long long i = 0; i <= cnt; i++) {
    cout << res[i].x1 << " " << res[i].y1 << " " << res[i].x2 << " "
         << res[i].y2 << '\n';
  }
  for (long long i = res.size() - 1; i > cnt; i--) {
    cout << res[i].x1 << " " << res[i].y1 << " " << res[i].x2 << " "
         << res[i].y2 << '\n';
  }
  return 0;
}

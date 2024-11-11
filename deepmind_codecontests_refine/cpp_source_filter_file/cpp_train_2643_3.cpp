#include <bits/stdc++.h>
using namespace std;
void err(istringstream &iss) {}
template <typename T, typename... Args>
void err(istringstream &iss, const T &varVal, const Args &...args) {
  string varName;
  iss >> varName;
  if (varName.back() == ',') varName.back() = ' ';
  cout << varName << " = " << varVal << "; ", err(iss, args...);
}
int n, m, K, T, Q, cn;
int ncr[55][55];
void nCr(int _n, int r) {
  for (int i = 0; i <= _n; i++) {
    int tmp = min(i, r);
    for (int j = 0; j <= tmp; j++) {
      ncr[i][j] = (j == 0 || j == i) ? 1 : (ncr[i - 1][j - 1] + ncr[i - 1][j]);
      if (ncr[i][j] >= 1000000007)
        ncr[i][j] -= 1000000007;
      else if (ncr[i][j] < 0)
        ncr[i][j] += 1000000007;
    }
  }
}
struct trio {
  bool opar;
  int cnt1, cnt2;
  bool operator==(const trio &rs) {
    return opar == rs.opar && cnt1 == rs.cnt1 && cnt2 == rs.cnt2;
  }
};
short a[55];
int lvl[2][55][55], ans[2][55][55], cnt[3];
void bfs() {
  queue<trio> q;
  q.push({0, cnt[1], cnt[2]});
  lvl[0][cnt[1]][cnt[2]] = 0, ans[0][cnt[1]][cnt[2]] = 1;
  while (!q.empty()) {
    trio u = q.front();
    q.pop();
    if (u == trio{1, cnt[1], cnt[2]}) return;
    int os2 = min(u.cnt2, K >> 1);
    for (int i = 0; i <= os2; i++) {
      int os1 = min(u.cnt1, K - (i << 1));
      for (int j = 0; j <= os1; j++) {
        if (i + j == 0) continue;
        int ncnt1 = cnt[1] - u.cnt1 + j, ncnt2 = cnt[2] - u.cnt2 + i;
        int &nlvl = lvl[!u.opar][ncnt1][ncnt2];
        if (nlvl != -1 && nlvl != lvl[u.opar][u.cnt1][u.cnt2] + 1) continue;
        int &os = ans[!u.opar][ncnt1][ncnt2];
        os += (int)1ll * ncr[u.cnt1][j] * ncr[u.cnt2][i] % 1000000007 *
              ans[u.opar][u.cnt1][u.cnt2] % 1000000007;
        if (os >= 1000000007)
          os -= 1000000007;
        else if (os < 0)
          os += 1000000007;
        if (nlvl != -1) continue;
        trio v = {!u.opar, ncnt1, ncnt2};
        q.push(v);
        nlvl = lvl[u.opar][u.cnt1][u.cnt2] + 1;
      }
    }
  }
}
int main() {
  cin.tie(NULL);
  scanf("%d%d", &n, &K);
  K /= 50;
  for (int i = 0; i < n; i++) {
    scanf("%hd", &a[i]), a[i] /= 50, cnt[a[i]]++;
  }
  nCr(55 - 1, 55 - 1), memset(lvl, -1, sizeof(lvl)), bfs();
  printf("%d\n%d\n", lvl[1][cnt[1]][cnt[2]], ans[1][cnt[1]][cnt[2]]);
  return 0;
}

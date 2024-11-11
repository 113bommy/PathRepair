#include <bits/stdc++.h>
using namespace std;
const int mod = 1000003;
const int maxn = 500010;
int n, m;
char str[maxn];
struct node {
  int lr, ud;
} ma[maxn];
inline char s(int i, int j) { return str[(i - 1) * m + (j - 1)]; }
int tran(int i, int j) { return (i - 1) * m + (j - 1); }
int solve() {
  int ret = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int ind = tran(i, j);
      char cha = s(i, j);
      if (cha >= '1' && cha <= '4') {
        if (cha == '1') {
          if (ma[ind].lr != 0 && ma[ind].lr != 1) return -1;
          if (ma[ind].ud != 0 && ma[ind].ud != 1) return -1;
          ma[ind].lr = 1;
          ma[ind].ud = 1;
          for (int k = i - 1; k >= 1; --k) {
            int tp = tran(k, j);
            if (ma[tp].ud == 0)
              ma[tp].ud = ((i - k) % 2 ? 2 : 1);
            else {
              if (ma[tp].ud != ((i - k) % 2 ? 2 : 1))
                return -1;
              else
                break;
            }
          }
          for (int k = i + 1; k <= n; ++k) {
            int tp = tran(k, j);
            if (ma[tp].ud == 0)
              ma[tp].ud = ((k - i) % 2 ? 2 : 1);
            else {
              if (ma[tp].ud != ((k - i) % 2 ? 2 : 1))
                return -1;
              else
                break;
            }
          }
          for (int k = j - 1; k >= 1; --k) {
            int tp = tran(i, k);
            if (ma[tp].lr == 0)
              ma[tp].lr = ((j - k) % 2 ? 2 : 1);
            else {
              if (ma[tp].lr != ((j - k) % 2 ? 2 : 1))
                return -1;
              else
                break;
            }
          }
          for (int k = j + 1; k <= m; ++k) {
            int tp = tran(i, k);
            if (ma[tp].lr == 0)
              ma[tp].lr = ((k - j) % 2 ? 2 : 1);
            else {
              if (ma[tp].lr != ((k - j) % 2 ? 2 : 1))
                return -1;
              else
                break;
            }
          }
        } else if (cha == '2') {
          if (ma[ind].lr != 0 && ma[ind].lr != 1) return -1;
          if (ma[ind].ud != 0 && ma[ind].ud != 2) return -1;
          ma[ind].lr = 1;
          ma[ind].ud = 2;
          for (int k = i - 1; k >= 1; --k) {
            int tp = tran(k, j);
            if (ma[tp].ud == 0)
              ma[tp].ud = ((i - k) % 2 ? 1 : 2);
            else {
              if (ma[tp].ud != ((i - k) % 2 ? 1 : 2))
                return -1;
              else
                break;
            }
          }
          for (int k = i + 1; k <= n; ++k) {
            int tp = tran(k, j);
            if (ma[tp].ud == 0)
              ma[tp].ud = ((k - i) % 2 ? 1 : 2);
            else {
              if (ma[tp].ud != ((k - i) % 2 ? 1 : 2))
                return -1;
              else
                break;
            }
          }
          for (int k = j - 1; k >= 1; --k) {
            int tp = tran(i, k);
            if (ma[tp].lr == 0)
              ma[tp].lr = ((j - k) % 2 ? 2 : 1);
            else {
              if (ma[tp].lr != ((j - k) % 2 ? 2 : 1))
                return -1;
              else
                break;
            }
          }
          for (int k = j + 1; k <= m; ++k) {
            int tp = tran(i, k);
            if (ma[tp].lr == 0)
              ma[tp].lr = ((k - j) % 2 ? 2 : 1);
            else {
              if (ma[tp].lr != ((k - j) % 2 ? 2 : 1))
                return -1;
              else
                break;
            }
          }
        } else if (cha == '3') {
          if (ma[ind].lr != 0 && ma[ind].lr != 2) return -1;
          if (ma[ind].ud != 0 && ma[ind].ud != 2) return -1;
          ma[ind].lr = 2;
          ma[ind].ud = 2;
          for (int k = i - 1; k >= 1; --k) {
            int tp = tran(k, j);
            if (ma[tp].ud == 0)
              ma[tp].ud = ((i - k) % 2 ? 1 : 2);
            else {
              if (ma[tp].ud != ((i - k) % 2 ? 1 : 2))
                return -1;
              else
                break;
            }
          }
          for (int k = i + 1; k <= n; ++k) {
            int tp = tran(k, j);
            if (ma[tp].ud == 0)
              ma[tp].ud = ((k - i) % 2 ? 1 : 2);
            else {
              if (ma[tp].ud != ((k - i) % 2 ? 1 : 2))
                return -1;
              else
                break;
            }
          }
          for (int k = j - 1; k >= 1; --k) {
            int tp = tran(i, k);
            if (ma[tp].lr == 0)
              ma[tp].lr = ((j - k) % 2 ? 1 : 2);
            else {
              if (ma[tp].lr != ((j - k) % 2 ? 1 : 2))
                return -1;
              else
                break;
            }
          }
          for (int k = j + 1; k <= m; ++k) {
            int tp = tran(i, k);
            if (ma[tp].lr == 0)
              ma[tp].lr = ((k - j) % 2 ? 1 : 2);
            else {
              if (ma[tp].lr != ((k - j) % 2 ? 1 : 2))
                return -1;
              else
                break;
            }
          }
        } else {
          if (ma[ind].lr != 0 && ma[ind].lr != 2) return -1;
          if (ma[ind].ud != 0 && ma[ind].ud != 1) return -1;
          ma[ind].lr = 2;
          ma[ind].ud = 1;
          for (int k = i - 1; k >= 1; --k) {
            int tp = tran(k, j);
            if (ma[tp].ud == 0)
              ma[tp].ud = ((i - k) % 2 ? 2 : 1);
            else {
              if (ma[tp].ud != ((i - k) % 2 ? 2 : 1))
                return -1;
              else
                break;
            }
          }
          for (int k = i + 1; k <= n; ++k) {
            int tp = tran(k, j);
            if (ma[tp].ud == 0)
              ma[tp].ud = ((k - i) % 2 ? 2 : 1);
            else {
              if (ma[tp].ud != ((k - i) % 2 ? 2 : 1))
                return -1;
              else
                break;
            }
          }
          for (int k = j - 1; k >= 1; --k) {
            int tp = tran(i, k);
            if (ma[tp].lr == 0)
              ma[tp].lr = ((j - k) % 2 ? 1 : 2);
            else {
              if (ma[tp].lr != ((j - k) % 2 ? 1 : 2))
                return -1;
              else
                break;
            }
          }
          for (int k = j + 1; k <= m; ++k) {
            int tp = tran(i, k);
            if (ma[tp].lr == 0)
              ma[tp].lr = ((k - j) % 2 ? 1 : 2);
            else {
              if (ma[tp].lr != ((k - j) % 2 ? 1 : 2))
                return -1;
              else
                break;
            }
          }
        }
      }
    }
  }
  map<int, bool> row, col;
  map<int, bool>::iterator it;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int ind = tran(i, j);
      if (!ma[ind].lr) row[i] = 1;
      if (!ma[ind].ud) col[j] = 1;
    }
  }
  for (int i = 1; i <= row.size(); ++i) ret = ret * 2 % mod;
  for (int i = 1; i <= col.size(); ++i) ret = ret * 2 % mod;
  return ret;
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    int ans = 0;
    memset(ma, 0, sizeof(ma));
    for (int i = 1; i <= n; ++i) scanf("%s", str + (i - 1) * m);
    int ret = solve();
    if (ret == -1)
      puts("0");
    else
      printf("%d\n", ret);
  }
  return 0;
}

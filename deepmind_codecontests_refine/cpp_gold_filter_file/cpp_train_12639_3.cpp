#include <bits/stdc++.h>
using namespace std;
clock_t __stt;
inline void TStart() { __stt = clock(); }
inline void TReport() {
  printf("\nTaken Time : %.3lf sec\n",
         (double)(clock() - __stt) / CLOCKS_PER_SEC);
}
template <typename T>
T MIN(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
T MAX(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
T ABS(T a) {
  return a > 0 ? a : (-a);
}
template <typename T>
void UMIN(T &a, T b) {
  if (b < a) a = b;
}
template <typename T>
void UMAX(T &a, T b) {
  if (b > a) a = b;
}
char s[100005];
long long di[100005][30], res, com[100005][30];
int H[100005], mul[100005], cnt[100005][30], glen[16], n;
struct SET {
  bool ok;
  vector<pair<int, int> > vc;
  SET(int OK = 0) {
    vc.clear();
    ok = OK;
  }
  void init(int OK = 0) {
    vc.clear();
    ok = OK;
  }
} cnd[16][100005];
SET inter(SET &a, SET &b) {
  if (a.ok || b.ok) return b.ok ? a : b;
  SET x;
  int i, j;
  for (i = 0, j = 0; i < (int)a.vc.size() && j < (int)b.vc.size();) {
    if (a.vc[i] == b.vc[j]) {
      x.vc.push_back(a.vc[i]);
      ++i;
      ++j;
    } else if (a.vc[i] < b.vc[j]) {
      ++i;
    } else {
      ++j;
    }
  }
  return x;
}
void exclude(int val, SET &S) {
  int i;
  vector<pair<int, int> > tmp;
  tmp.clear();
  vector<pair<int, int> > &vc = S.vc;
  for (i = 0; i < (int)vc.size(); ++i) {
    if (vc[i].second != val) tmp.push_back(vc[i]);
  }
  vc = tmp;
}
inline int count(int l, int r, char c) {
  if (l) return cnt[r][c - 'a'] - cnt[l - 1][c - 'a'];
  return cnt[r][c - 'a'];
}
inline bool cmp(int a, int b, int c, int d) {
  long long val1, val2;
  if (b - a != d - c) return 0;
  if (b < a && d < c) return 1;
  if (a) {
    val1 = H[b] - H[a - 1] * mul[b - a + 1];
  } else {
    val1 = H[b];
  }
  if (c) {
    val2 = H[d] - H[c - 1] * mul[d - c + 1];
  } else {
    val2 = H[d];
  }
  return val1 == val2;
}
inline int pre(int a, int b, int c, int d) {
  int L = 0, H = b - a + 1, mid;
  while (L < H) {
    mid = ((L + H + 1) >> 1);
    if (cmp(a, a + mid - 1, c, c + mid - 1))
      L = mid;
    else
      H = mid - 1;
  }
  return L;
}
inline int diff(int a, int b, int x, int y) {
  int cur = pre(a, b, x, y);
  if (cur == b - a + 1) return -1;
  if (cur == b - a) return cur;
  if (pre(a + cur + 1, b, x + cur + 1, y) + cur >= b - a)
    return cur;
  else
    return -2;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  int i, j, k;
  glen[0] = 1;
  for (i = 1; i < 16; ++i) glen[i] = glen[i - 1] * 2 + 1;
  for (i = 0; i < n; ++i) ++cnt[i][s[i] - 'a'];
  for (i = 1; i < n; ++i)
    for (j = 0; j < 26; ++j) cnt[i][j] += cnt[i - 1][j];
  mul[0] = 1;
  for (i = 1; i <= n; ++i) mul[i] = mul[i - 1] * 257;
  H[0] = s[0];
  for (i = 1; i < n; ++i) H[i] = (int)s[i] + H[i - 1] * 257;
  for (i = 0; i < 16; ++i) {
    for (j = 0; j < n; ++j) {
      if (j + glen[i] - 1 >= n) break;
      int lv = j, rv = j + glen[i] - 1, mv = j + (glen[i] - 1) / 2;
      long long dlt = ((long long)(rv - lv + 1)) * ((long long)(rv - lv + 1)),
                cv = diff(lv, mv - 1, mv + 1, rv);
      if (i > 0)
        cnd[i][j] = inter(cnd[i - 1][j], cnd[i - 1][mv + 1]);
      else
        cnd[i][j].init(1);
      if (cv == -2)
        cnd[i][j].init();
      else if (cv != -1) {
        SET x;
        x.vc.push_back(make_pair(lv + cv, s[mv + cv + 1]));
        x.vc.push_back(make_pair(mv + cv + 1, s[lv + cv]));
        cnd[i][j] = inter(cnd[i][j], x);
      }
      exclude(s[mv], cnd[i][j]);
      if (count(lv, rv, s[mv]) > 2 && (count(lv, rv, s[mv]) & 1)) {
        SET x;
        for (k = 0; k < 26; ++k) {
          if (count(lv, rv, k + 'a') == 0)
            x.vc.push_back(make_pair(mv, k + 'a'));
        }
        cnd[i][j] = inter(x, cnd[i][j]);
      } else if (count(lv, rv, s[mv]) > 2)
        cnd[i][j].init();
      if (cnd[i][j].ok) {
        res += dlt;
        for (k = 0; k < 26; ++k) {
          di[0][k] += dlt;
          di[lv][k] -= dlt;
          di[rv + 1][k] += dlt;
          if (!count(lv, rv, k + 'a')) {
            com[mv][k] += dlt;
          }
        }
      } else {
        for (k = 0; k < (int)cnd[i][j].vc.size(); ++k) {
          com[cnd[i][j].vc[k].first][cnd[i][j].vc[k].second - 'a'] += dlt;
        }
      }
    }
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < 26; ++j) {
      if (i > 0) {
        di[i][j] += di[i - 1][j];
      }
      UMAX(res, di[i][j] + com[i][j]);
    }
  }
  printf("%I64d\n", res);
  return 0;
}

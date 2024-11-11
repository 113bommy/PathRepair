#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int oo = 0x3f3f3f3f;
const int maxn = 100100, maxm = 100100, maxabs = 100100;
int lim[3], n, m, K;
int lim1d[3][2];
int lim2d[3][4][maxabs + 5];
struct data {
  int first, second, z;
  int id;
  data(int _x = 0, int _y = 0, int _z = 0, int _id = -1)
      : first(_x), second(_y), z(_z), id(_id) {}
  friend bool operator<(const data &first, const data &second) {
    return first.first < second.first;
  }
};
vector<data> lim3d[8];
vector<data> q3d[8];
int good[3][2];
int ans[maxm + 5];
int main() {
  for (int i = (0), i_end_ = (3); i < i_end_; ++i) scanf("%d", lim + i);
  scanf("%d%d%d", &n, &m, &K);
  for (int i = (0), i_end_ = (3); i < i_end_; ++i)
    for (int j = (0), j_end_ = (2); j < j_end_; ++j) {
      if (j & 1)
        lim1d[i][j] = oo, good[i][j] = -oo;
      else
        lim1d[i][j] = -oo, good[i][j] = oo;
    }
  for (int i = (0), i_end_ = (3); i < i_end_; ++i)
    for (int j = (0), j_end_ = (4); j < j_end_; ++j) {
      if (j >> 1 & 1)
        for (int k = (0), k_end_ = (maxabs); k < k_end_; ++k)
          lim2d[i][j][k] = oo;
      else
        for (int k = (0), k_end_ = (maxabs); k < k_end_; ++k)
          lim2d[i][j][k] = -oo;
    }
  int a[3];
  for (int i = (0), i_end_ = (n); i < i_end_; ++i) {
    for (int j = (0), j_end_ = (3); j < j_end_; ++j) {
      scanf("%d", a + j);
      for (int k = (0), k_end_ = (2); k < k_end_; ++k)
        if (k)
          chkmax(good[j][k], a[j]);
        else
          chkmin(good[j][k], a[j]);
    }
  }
  for (int i = (0), i_end_ = (m); i < i_end_; ++i) {
    for (int j = (0), j_end_ = (3); j < j_end_; ++j) {
      scanf("%d", a + j);
    }
    static int ty[3];
    int cnt = 0;
    for (int j = (0), j_end_ = (3); j < j_end_; ++j) {
      if (a[j] < good[j][0]) ty[j] = -1;
      if (good[j][0] <= a[j] && a[j] <= good[j][1]) ty[j] = 0;
      if (good[j][1] < a[j]) ty[j] = 1;
      if (!ty[j]) ++cnt;
    }
    if (cnt == 3) {
      puts("INCORRECT");
      return 0;
    }
    if (cnt == 2) {
      for (int j = (0), j_end_ = (3); j < j_end_; ++j)
        if (ty[j]) {
          if (ty[j] == -1)
            chkmax(lim1d[j][0], a[j]);
          else
            chkmin(lim1d[j][1], a[j]);
        }
    }
    if (cnt == 1) {
      for (int j = (0), j_end_ = (3); j < j_end_; ++j)
        if (!ty[j]) {
          int tmp = 0;
          for (int k = (0), k_end_ = (2); k < k_end_; ++k) {
            if (ty[(j + k + 1) % 3] == 1) tmp |= 1 << k;
          }
          if (ty[(j + 2) % 3] == 1)
            chkmin(lim2d[j][tmp][a[(j + 1) % 3]], a[(j + 2) % 3]);
          else
            chkmax(lim2d[j][tmp][a[(j + 1) % 3]], a[(j + 2) % 3]);
        }
    }
    if (cnt == 0) {
      int tmp = 0;
      for (int j = (0), j_end_ = (3); j < j_end_; ++j) {
        if (ty[j] == 1) tmp |= 1 << j;
      }
      lim3d[tmp].push_back(data(a[0], a[1], a[2]));
    }
  }
  for (int i = (0), i_end_ = (3); i < i_end_; ++i)
    for (int j = (0), j_end_ = (4); j < j_end_; ++j) {
      if (j & 1) {
        for (int k = (0), k_end_ = (maxabs - 1); k < k_end_; ++k) {
          if (j >> 1)
            chkmin(lim2d[i][j][k + 1], lim2d[i][j][k]);
          else
            chkmax(lim2d[i][j][k + 1], lim2d[i][j][k]);
        }
      } else {
        for (int k = maxabs - 1; k >= 1; --k) {
          if (j >> 1)
            chkmin(lim2d[i][j][k - 1], lim2d[i][j][k]);
          else
            chkmax(lim2d[i][j][k - 1], lim2d[i][j][k]);
        }
      }
    }
  puts("CORRECT");
  for (int i = (0), i_end_ = (K); i < i_end_; ++i) {
    ans[i] = 0;
    for (int j = (0), j_end_ = (3); j < j_end_; ++j) scanf("%d", a + j);
    bool open = 1;
    for (int j = (0), j_end_ = (3); j < j_end_; ++j) {
      if (a[j] < good[j][0] || a[j] > good[j][1]) {
        open = 0;
        break;
      }
    }
    if (open) {
      ans[i] = 1;
      continue;
    }
    bool closed = 0;
    for (int j = (0), j_end_ = (3); j < j_end_; ++j)
      if (a[j] <= lim1d[j][0] || a[j] >= lim1d[j][1]) closed = 1;
    for (int j = (0), j_end_ = (3); j < j_end_; ++j)
      for (int k = (0), k_end_ = (4); k < k_end_; ++k) {
        if (k >> 1) {
          if (a[(j + 2) % 3] >= lim2d[j][k][a[(j + 1) % 3]]) closed = 1;
        } else {
          if (a[(j + 2) % 3] <= lim2d[j][k][a[(j + 1) % 3]]) closed = 1;
        }
      }
    if (closed)
      ans[i] = -1;
    else {
      int tmp = 0;
      bool flag = 0;
      for (int j = (0), j_end_ = (3); j < j_end_; ++j) {
        if (good[j][0] <= a[j] && a[j] <= good[j][1]) flag = 1;
        if (good[j][1] < a[j]) tmp |= 1 << j;
      }
      if (!flag) q3d[tmp].push_back(data(a[0], a[1], a[2], i));
    }
  }
  for (int i = (0), i_end_ = (8); i < i_end_; ++i) {
    sort((lim3d[i]).begin(), (lim3d[i]).end());
    sort((q3d[i]).begin(), (q3d[i]).end());
    if (!(i & 1)) {
      reverse((lim3d[i]).begin(), (lim3d[i]).end());
      reverse((q3d[i]).begin(), (q3d[i]).end());
    }
    static int fen[maxabs + 5];
    if (i >> 2 & 1)
      memset(fen, oo, sizeof fen);
    else
      memset(fen, -oo, sizeof fen);
    int k = 0;
    for (int j = (0), j_end_ = ((int((q3d[i]).size()))); j < j_end_; ++j) {
      while (k < (int((lim3d[i]).size()))) {
        if (i & 1) {
          if (lim3d[i][k].first > q3d[i][j].first) break;
        } else {
          if (lim3d[i][k].first < q3d[i][j].first) break;
        }
        if (i >> 1 & 1) {
          for (int l = lim3d[i][k].second; l < maxabs; l += l & -l) {
            if (i >> 2 & 1)
              chkmin(fen[l], lim3d[i][k].z);
            else
              chkmax(fen[l], lim3d[i][k].z);
          }
        } else {
          for (int l = lim3d[i][k].second; l > 0; l -= l & -l)
            if (i >> 2 & 1)
              chkmin(fen[l], lim3d[i][k].z);
            else
              chkmax(fen[l], lim3d[i][k].z);
        }
        ++k;
      }
      int ret = (i >> 2 & 1) ? oo : -oo;
      if (i >> 1 & 1) {
        for (int l = q3d[i][k].second; l > 0; l -= l & -l)
          if (i >> 2 & 1)
            chkmin(ret, fen[l]);
          else
            chkmax(ret, fen[l]);
      } else {
        for (int l = q3d[i][k].second; l < maxabs; l += l & -l)
          if (i >> 2 & 1)
            chkmin(ret, fen[l]);
          else
            chkmax(ret, fen[l]);
      }
      if (i >> 2 & 1) {
        if (ret <= q3d[i][k].z) ans[q3d[i][k].id] = -1;
      } else {
        if (ret >= q3d[i][k].z) ans[q3d[i][k].id] = -1;
      }
    }
  }
  for (int i = (0), i_end_ = (K); i < i_end_; ++i) {
    if (ans[i] == 1)
      puts("OPEN");
    else if (ans[i] == 0)
      puts("UNKNOWN");
    else if (ans[i] == -1)
      puts("CLOSED");
  }
  return 0;
}

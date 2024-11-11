#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                         {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
int n;
int u[500010], v[500010];
char c[500010];
int cnt[500010];
int cnt_[500010];
int main() {
  int T;
  scanf("%d", &T);
  for (; T > 0; T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
      scanf("%d%d", &u[i], &v[i]);
    }
    scanf("\n");
    for (int i = 1; i <= n; i++) scanf("%c", &c[i]);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n - 1; i++) {
      cnt[u[i]]++;
      cnt[v[i]]++;
    }
    if (n <= 2) {
      puts("Draw");
      continue;
    }
    int d = 0;
    for (int i = 1; i <= n; i++) {
      d = max(d, cnt[i]);
    }
    if (d >= 4) {
      puts("White");
      continue;
    }
    if (d == 3) {
      if (n == 4) {
        if (c[1] == 'W' || c[2] == 'W' || c[3] == 'W' || c[4] == 'W') {
          puts("White");
        } else
          puts("Draw");
        continue;
      }
      for (int i = 1; i <= n; i++) cnt_[i] = 0;
      for (int i = 1; i <= n - 1; i++) {
        if (cnt[u[i]] >= 2) cnt_[v[i]]++;
        if (cnt[v[i]] >= 2) cnt_[u[i]]++;
      }
      bool ret = false;
      for (int i = 1; i <= n; i++) {
        if (cnt[i] == 3 && cnt_[i] >= 2) {
          ret = true;
          break;
        }
      }
      if (ret) {
        puts("White");
        continue;
      }
      for (int i = 1; i <= n; i++) {
        if (cnt[i] >= 2 && c[i] == 'W') {
          ret = true;
          break;
        }
      }
      if (ret) {
        puts("White");
        continue;
      }
      for (int i = 1; i <= n - 1; i++) {
        if (cnt[u[i]] == 3 && cnt[v[i]] == 1 && c[v[i]] == 'W') {
          ret = true;
          break;
        }
        if (cnt[v[i]] == 3 && cnt[u[i]] == 1 && c[u[i]] == 'W') {
          ret = true;
          break;
        }
      }
      if (ret) {
        puts("White");
        continue;
      }
      int CNT = 0;
      for (int i = 1; i <= n; i++) {
        if (cnt[i] == 3) CNT++;
      }
      if (CNT == 1) {
        for (int i = 1; i <= n; i++)
          if (c[i] == 'W') CNT++;
        if (CNT == 2 && n % 2 == 0) {
          puts("White");
        } else
          puts("Draw");
        continue;
      } else {
        if (n % 2 == 1) {
          puts("White");
        } else
          puts("Draw");
        continue;
      }
    }
    int cnt_w[2] = {};
    for (int i = 1; i <= n; i++) {
      if (c[i] == 'W') {
        cnt_w[cnt[i] - 1]++;
      }
    }
    if (cnt_w[1] > 0) {
      if (n == 3 && cnt_w[0] == 0) {
        puts("Draw");
        continue;
      }
      puts("White");
      continue;
    }
    if (cnt_w[0] == 2 && (n & 1)) {
      puts("White");
      continue;
    } else
      puts("Draw");
  }
}

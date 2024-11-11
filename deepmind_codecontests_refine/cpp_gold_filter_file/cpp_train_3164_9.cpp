#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T sqr(T x) {
  return x * x;
}
const double EPS = 1e-9;
const int MAXN = 1e3 + 10;
bool hor[MAXN][MAXN];
bool ver[MAXN][MAXN];
int k, h, w;
char buf[MAXN];
int a[MAXN][MAXN];
int main() {
  cin >> h >> w >> k;
  scanf("\n");
  for (int i = 0; i < (int)2 * h - 1; ++i) {
    gets(buf);
    if (i & 1) {
      for (int j = 0; j < (int)w; ++j) {
        ver[i / 2][j] = buf[j] == 'E';
      }
    } else {
      for (int j = 0; j < (int)w - 1; ++j) {
        hor[i / 2][j] = buf[j] == 'E';
      }
    }
  }
  if (k == 1) {
    int all = 0;
    int good = 0;
    for (int i = 0; i < (int)h; ++i) {
      for (int j = 0; j < (int)w - 1; ++j) {
        ++all;
        good += hor[i][j];
      }
    }
    for (int i = 0; i < (int)h - 1; ++i) {
      for (int j = 0; j < (int)w; ++j) {
        ++all;
        good += ver[i][j];
      }
    }
    if (good * 4 >= all * 3) {
      puts("YES");
      for (int i = 0; i < (int)h; ++i) {
        for (int j = 0; j < (int)w; ++j) {
          printf("1 ");
        }
        puts("");
      }
    } else {
      puts("NO");
    }
    return 0;
  }
  if ((w - 1) * h + ((w + 1) / 2) * (h - 1) >
      (h - 1) * w + ((h + 1) / 2) * (w - 1)) {
    a[0][0] = 0;
    for (int j = 1; j < w; ++j) {
      if (hor[0][j - 1]) {
        a[0][j] = a[0][j - 1];
      } else {
        a[0][j] = a[0][j - 1] ^ 1;
      }
    }
    for (int i = 1; i < h; ++i) {
      vector<int> ok(2, 0);
      for (int c = 0; c < (int)2; ++c) {
        a[i][0] = c;
        for (int j = 1; j < w; ++j) {
          a[i][j] = a[i][j - 1] ^ (!hor[i][j - 1]);
        }
        for (int j = 0; j < (int)w; ++j) {
          ok[c] += ver[i - 1][j] == (a[i][j] == a[i - 1][j]);
        }
      }
      if (ok[0] > ok[1]) {
        a[i][0] = 0;
        for (int j = 1; j < w; ++j) {
          a[i][j] = a[i][j - 1] ^ (!hor[i][j - 1]);
        }
      }
    }
  } else {
    a[0][0] = 0;
    for (int i = 1; i < h; ++i) {
      a[i][0] = a[i - 1][0] ^ (!ver[i - 1][0]);
    }
    for (int j = 1; j < w; ++j) {
      vector<int> ok(2, 0);
      for (int c = 0; c < (int)2; ++c) {
        a[0][j] = c;
        for (int i = 1; i < h; ++i) {
          a[i][j] = a[i - 1][j] ^ (!ver[i - 1][j]);
        }
        for (int i = 0; i < (int)h; ++i) {
          ok[c] += hor[i][j - 1] == (a[i][j] == a[i][j - 1]);
        }
      }
      if (ok[0] > ok[1]) {
        a[0][j] = 0;
        for (int i = 1; i < h; ++i) {
          a[i][j] = a[i - 1][j] ^ (!ver[i - 1][j]);
        }
      }
    }
  }
  puts("YES");
  for (int i = 0; i < (int)h; ++i) {
    for (int j = 0; j < (int)w; ++j) {
      printf("%d ", a[i][j] + 1);
    }
    puts("");
  }
  return 0;
}

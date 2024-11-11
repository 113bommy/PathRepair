#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
bool t[41][41];
int cnt[41][41];
int cnt2[41][41][41][41];
int n, m, q;
bool empty(int x1, int y1, int x2, int y2) {
  return (cnt[x2 + 1][y2 + 1] - cnt[x1][y2 + 1] - cnt[x2 + 1][y1] +
          cnt[x1][y1]) == 0;
};
int dp[41][41][41][41];
void licz(int x1, int y1, int x2, int y2) {
  int e = empty(x1, y1, x2, y2);
  int qq;
  if (x1 == x2 && y1 == y2) {
    qq = e;
    dp[x1][y1][x2][y2] = qq;
  } else if (x1 == x2) {
    qq = cnt2[x1][y1 + 1][x2][y2] + e;
    dp[x1][y1][x2][y2] = dp[x1][y1][x2][y2 - 1] + qq;
  } else if (y1 == y2) {
    qq = cnt2[x1 + 1][y1][x2][y2] + e;
    dp[x1][y1][x2][y2] = dp[x1][y1][x2 - 1][y2] + qq;
  } else {
    qq = cnt2[x1 + 1][y1][x2][y2] + cnt2[x1][y1 + 1][x2][y2] -
         cnt2[x1 + 1][y1 + 1][x2][y2] + e;
    dp[x1][y1][x2][y2] = dp[x1][y1][x2 - 1][y2] + dp[x1][y1][x2][y2 - 1] -
                         dp[x1][y1][x2 - 1][y2 - 1] + qq;
  };
  cnt2[x1][y1][x2][y2] = qq;
};
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < (n); ++i) {
    scanf("\n");
    for (int j = 0; j < (m); ++j) {
      char c;
      scanf("%c", &c);
      t[i][j] = c == '1';
    };
  };
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      cnt[i][j] =
          cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + t[i - 1][j - 1];
    };
  for (int di = 0; di < (n); ++di)
    for (int dj = 0; dj < (n); ++dj) {
      for (int i = 0; i < (n - di); ++i)
        for (int j = 0; j < (n - dj); ++j) {
          licz(i, j, i + di, j + dj);
        };
    }
  for (int i = 0; i < (q); ++i) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--;
    y1--;
    x2--;
    y2--;
    printf("%d\n", dp[x1][y1][x2][y2]);
  };
  return 0;
}

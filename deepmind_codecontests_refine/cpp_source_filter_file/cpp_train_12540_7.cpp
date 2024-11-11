#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T min(T &a, T &b) {
  return a < b ? a : b;
}
template <class T>
inline T max(T &a, T &b) {
  return a > b ? a : b;
}
template <class T>
void read(T &x) {
  char ch;
  while ((ch = getchar()) && !isdigit(ch))
    ;
  x = ch - '0';
  while ((ch = getchar()) && isdigit(ch)) x = x * 10 + ch - '0';
}
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
};
char s1[2010], s2[510];
int l1, l2, dp[2010][510], id[100], pre[2010][100], fin[2010];
int main() {
  scanf("%s%s", s1 + 1, s2 + 1);
  l1 = strlen(s1 + 1), l2 = strlen(s2 + 1);
  for (int i = 1; i <= l1; i++) {
    id[s1[i] - 'a'] = i;
    for (int j = 0; j <= 25; j++) pre[i][j] = id[j];
  }
  for (int i = 1; i <= l1; i++) {
    int c = i;
    for (int j = l2; j >= 1; j--) c = pre[c][s2[j] - 'a'] - 1;
    fin[i] = c;
  }
  for (int i = 0; i <= l1; i++)
    for (int j = 0; j <= l1; j++) dp[i][j] = -1000000;
  dp[0][0] = 0;
  for (int i = 1; i <= l1; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = max(j > 0 ? dp[i - 1][j - 1] : 0, dp[i - 1][j]);
      if (fin[i] >= 0 && j >= i - fin[i] - l2)
        dp[i][j] = max(dp[i][j], dp[fin[i]][j - (i - fin[i] - l2)] + 1);
    }
  }
  for (int i = 0; i <= l1; i++) printf("%d ", dp[l1][i]);
}

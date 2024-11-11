#include <bits/stdc++.h>
using namespace std;
int n, m, q;
string s;
int a[2000];
int dp[30][2000];
int cnt[30];
char c;
void init(int x, int y) {
  memset(cnt, 0, sizeof cnt);
  for (int i = (x), _i = (y + 1); i < _i; ++i) {
    cnt[a[i]]++;
  }
  int sz = y - x + 1;
  for (int i = 0, _i = (26); i < _i; ++i) {
    int need = sz - cnt[i];
    dp[i][need] = max(dp[i][need], sz);
  }
}
int main() {
  scanf("%d\n", &n);
  getline(cin, s);
  for (int i = 0, _i = (n); i < _i; ++i) a[i] = s[i] - 'a';
  for (int i = 0, _i = (n); i < _i; ++i) {
    for (int j = (i), _j = (n); j < _j; ++j) {
      init(i, j);
    }
  }
  for (int i = 0, _i = (26); i < _i; ++i) {
    for (int j = (1), _j = (n); j < _j; ++j) {
      dp[i][j] = max(dp[i][j], dp[i][j - 1]);
    }
  }
  scanf("%d", &q);
  for (int i = 0, _i = (q); i < _i; ++i) {
    scanf("%d %c", &m, &c);
    int cc = c - 'a';
    cout << dp[cc][m] << endl;
  }
  return 0;
}

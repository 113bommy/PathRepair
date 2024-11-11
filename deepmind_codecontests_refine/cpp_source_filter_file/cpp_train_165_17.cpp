#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200042, B = 30;
int tab[MAXN], gol[MAXN][32], gor[MAXN][32];
int bigl[MAXN], bigr[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    int x;
    cin >> x;
    tab[i] = x;
  }
  for (int i = (1); i <= (n); ++i) {
    for (int j = (0); j <= (B); ++j) {
      if ((1 << j) & tab[i])
        gol[i][j] = i;
      else
        gol[i][j] = gol[i - 1][j];
    }
  }
  for (int j = (1); j <= (B); ++j) gor[n + 1][j] = n + 1;
  for (int i = n; i >= 1; i--) {
    for (int j = (0); j <= (B); ++j) {
      if ((1 << j) & tab[i])
        gor[i][j] = i;
      else
        gor[i][j] = gor[i + 1][j];
    }
  }
  stack<int> S;
  for (int i = (1); i <= (n); ++i) {
    while (!S.empty() && tab[S.top()] < tab[i]) S.pop();
    if (S.empty())
      bigl[i] = 0;
    else
      bigl[i] = S.top();
    S.push(i);
  }
  while (!S.empty()) S.pop();
  for (int i = n; i >= 1; i--) {
    while (!S.empty() && tab[S.top()] <= tab[i]) S.pop();
    if (S.empty())
      bigr[i] = n + 1;
    else
      bigr[i] = S.top();
    S.push(i);
  }
  long long res = 0;
  for (int i = (1); i <= (n); ++i) {
    int l = bigl[i] + 1, r = bigr[i] - 1;
    int lb = 0, rb = n + 1;
    for (int b = (0); b <= (B); ++b) {
      if (((1 << b) & tab[i]) == 0) lb = max(lb, gol[i][b]);
      if (((1 << b) & tab[i]) == 0) rb = min(rb, gor[i][b]);
    }
    if (lb >= l) res += 1LL * (lb - l + 1) * (r - i + 1);
    if (rb <= r) res += 1LL * (r - rb + 1) * (i - l + 1);
    if (lb >= l && rb <= r) res -= 1LL * (lb - l + 1) * (r - rb + 1);
  }
  cout << res << "\n";
  return 0;
}

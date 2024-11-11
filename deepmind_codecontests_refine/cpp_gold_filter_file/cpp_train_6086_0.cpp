#include <bits/stdc++.h>
using namespace std;
int n, t;
int s[100013];
int g[17][100013];
int lg[100013];
vector<pair<int, int> > sorted;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int query(int l, int r) {
  int tmp = l;
  int _log = lg[r - l + 1];
  int gcf = gcd(g[_log][l], g[_log][r - (1 << _log) + 1]);
  vector<pair<int, int> >::iterator left =
      lower_bound(sorted.begin(), sorted.end(), make_pair(gcf, l));
  vector<pair<int, int> >::iterator right =
      upper_bound(sorted.begin(), sorted.end(), make_pair(gcf, r));
  return r - l + 1 - (right - left);
}
int main() {
  scanf("%d", &n);
  int l = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
    sorted.push_back(make_pair(s[i], i));
    if (i == (1 << (l + 1))) l++;
    lg[i] = l;
  }
  sort(sorted.begin(), sorted.end());
  for (int i = 1; i <= n; i++) {
    g[0][i] = s[i];
  }
  for (int i = 1; i <= 16; i++) {
    for (int j = 1; j <= n; j++) {
      g[i][j] = gcd(g[i - 1][j], g[i - 1][min(n, j + (1 << (i - 1)))]);
    }
  }
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", query(l, r));
  }
}

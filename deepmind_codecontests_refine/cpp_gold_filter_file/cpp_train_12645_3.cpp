#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
long long powm(long long a, long long p, long long m) {
  long long r = 1 % m;
  while (p) {
    if (p & 1) r = r * a % m;
    p >>= 1;
    a = a * a % m;
  }
  return r;
}
int win[2][100001];
int main() {
  int n, a;
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    scanf("%d", &a);
    win[0][i + 1] = win[0][i] + (a == 1);
    win[1][i + 1] = win[1][i] + (a == 2);
  }
  vector<pair<int, int> > ans;
  for (int t = 1; t <= n; ++t) {
    int c = 0, s[2] = {}, last = -1;
    while (c < n) {
      int a = c, b = n;
      while (b - a > 1) {
        int m = (a + b + 1) / 2;
        if (win[0][m] - win[0][c] < t && win[1][m] - win[1][c] < t)
          a = m;
        else
          b = m;
      }
      if (win[0][b] - win[0][c] == t)
        s[0]++, c = b, last = 0;
      else if (win[1][b] - win[1][c] == t)
        s[1]++, c = b, last = 1;
      else
        c = n + 1;
    }
    if (c == n && (s[0] < s[1] && last == 1 || s[0] > s[1] && last == 0))
      ans.push_back(make_pair(max(s[0], s[1]), t));
  }
  printf("%d\n", ((int)(ans).size()));
  sort((ans).begin(), (ans).end());
  for (int i = 0; i < (((int)(ans).size())); ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}

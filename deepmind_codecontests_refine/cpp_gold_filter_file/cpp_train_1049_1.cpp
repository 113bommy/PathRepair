#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int n, diam, mxdeg;
vector<pair<int, int>> e;
void rec(int at, int dep, int &nxt) {
  if (nxt >= n || dep == 0) return;
  for (int i = (0); i < (mxdeg - 1); ++i)
    if (nxt < n) {
      int to = nxt++;
      e.push_back(make_pair(at, to));
      rec(to, dep - 1, nxt);
    }
}
bool solve() {
  e.clear();
  if (diam > n - 1) return false;
  if (n == 1) return true;
  if (n > 2 && mxdeg < 2) return false;
  for (int i = (0); i < (diam); ++i) e.push_back(make_pair(i, i + 1));
  int nxt = diam + 1;
  for (int i = (1); i <= (diam - 1); ++i)
    if (nxt < n)
      for (int j = (0); j < (mxdeg - 2); ++j)
        if (nxt < n) {
          int at = nxt++;
          e.push_back(make_pair(i, at));
          rec(at, min(i, diam - i) - 1, nxt);
        }
  return nxt == n;
}
void run() {
  scanf("%d%d%d", &n, &diam, &mxdeg);
  if (!solve()) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (int i = (0); i < (((int)(e).size())); ++i)
    printf("%d %d\n", e[i].first + 1, e[i].second + 1);
}
int main() {
  run();
  return 0;
}

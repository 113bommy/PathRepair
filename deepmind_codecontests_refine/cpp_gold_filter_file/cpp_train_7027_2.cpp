#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<pair<long long, long long>, int> xx[100010], yy[100010];
pair<long long, long long> p[100010];
bool mark[100010];
void setup() {
  long long x1, y1, x2, y2;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    xx[i] = make_pair(make_pair(x1 + x2, y1 + y2), i);
    yy[i] = make_pair(make_pair(y1 + y2, x1 + x2), i);
    p[i] = make_pair(x1 + x2, y1 + y2);
  }
  sort(xx + 1, xx + n + 1);
  sort(yy + 1, yy + n + 1);
  memset(mark, 0, sizeof(mark));
}
long long best(int lowX, int hiX, int lowY, int hiY, int k) {
  while (mark[xx[lowX].second]) lowX++;
  while (mark[xx[hiX].second]) hiX--;
  while (mark[yy[lowY].second]) lowY++;
  while (mark[yy[hiY].second]) hiY--;
  if (k == 0) {
    int lxi, hxi, lyi, hyi;
    lxi = xx[lowX].second;
    hxi = xx[hiX].second;
    lyi = yy[lowY].second;
    hyi = yy[hiY].second;
    long long x = max(1ll, (p[hxi].first - p[lxi].first + 1) / 2);
    long long y = max(1ll, (p[hyi].second - p[lyi].second + 1) / 2);
    return x * y;
  }
  long long a;
  mark[xx[lowX].second] = true;
  a = best(lowX + 1, hiX, lowY, hiY, k - 1);
  mark[xx[lowX].second] = false;
  mark[xx[hiX].second] = true;
  a = min(a, best(lowX, hiX - 1, lowY, hiY, k - 1));
  mark[xx[hiX].second] = false;
  mark[yy[lowY].second] = true;
  a = min(a, best(lowX, hiX, lowY + 1, hiY, k - 1));
  mark[yy[lowY].second] = false;
  mark[yy[hiY].second] = true;
  a = min(a, best(lowX, hiX, lowY, hiY - 1, k - 1));
  mark[yy[hiY].second] = false;
  return a;
}
void xuly() { cout << best(1, n, 1, n, k); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  setup();
  xuly();
  return 0;
}

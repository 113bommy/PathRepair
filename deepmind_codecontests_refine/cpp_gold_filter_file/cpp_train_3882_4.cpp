#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::fixed;
using std::make_pair;
using std::max;
using std::min;
using std::pair;
using std::set;
using std::sort;
const long long base = (long long)(5 * 1e8 + 5);
const long long coefficient = (long long)(4 * 1e9);
long long convertCoordinate(long long x, long long y) {
  return (x + base) * coefficient + (y + base);
}
pair<long long, long long> convertCoordinateBack(long long pos) {
  long long x = pos / coefficient - base - base;
  long long y = pos % coefficient - base - base;
  return make_pair(x, y);
}
const int MaxN = 200000 + 9;
int n, k, l, r, used;
long long points[MaxN];
long long x, y, now;
set<long long> waitList;
set<pair<long long, long long> > ans;
set<long long>::iterator it;
set<pair<long long, long long> >::iterator pit;
int main() {
  waitList.clear();
  ans.clear();
  scanf("%d%d", &n, &k);
  if (k >= n) return cout << "-1\n", 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d%I64d", &x, &y);
    points[i] = convertCoordinate(x, y);
  }
  sort(points + 1, points + n + 1);
  for (int i = 1; i <= min(k + 2, n); i++) {
    for (int j = max(n - k - 2, 1); j <= n; j++) {
      waitList.insert(points[i] + points[j]);
    }
  }
  for (it = waitList.begin(); it != waitList.end(); it++) {
    l = 1;
    r = n;
    used = 0;
    while (l <= r) {
      now = points[l] + points[r];
      if (now < (*it))
        l++, used++;
      else if (now > (*it))
        r--, used++;
      else
        l++, r--;
    }
    if (used <= k) ans.insert(convertCoordinateBack(*it));
  }
  if (ans.size() == 0)
    printf("0\n");
  else {
    printf("%d\n", ans.size());
    for (pit = ans.begin(); pit != ans.end(); pit++) {
      printf("%.2lf %.2lf\n", (double)(*pit).first * 0.5,
             (double)(*pit).second * 0.5);
    }
  }
}

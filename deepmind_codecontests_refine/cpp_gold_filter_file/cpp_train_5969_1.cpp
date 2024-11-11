#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    pair<int, int> p1, p2;
    int n, m, x1, y1, x2, y2;
    scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
    swap(m, n);
    p1 = make_pair(x1, y1);
    p2 = make_pair(x2, y2);
    if (p1.first > p2.first) swap(p1, p2);
    pair<pair<int, int>, pair<int, int> > r1, r2;
    r1.first = make_pair(1, p1.first + m - p2.first);
    r1.second = make_pair(1, p1.second + n - p2.second);
    if (p1.second > p2.second)
      r1.second = make_pair(p1.second - p2.second + 1, n);
    r2.first = make_pair(p2.first - p1.first + 1, m);
    r2.second = make_pair(1, p2.second + n - p1.second);
    if (p2.second > p1.second)
      r2.second = make_pair(p2.second - p1.second + 1, n);
    pair<pair<int, int>, pair<int, int> > un;
    un.first.first = max(r1.first.first, r2.first.first);
    un.first.second = min(r1.first.second, r2.first.second);
    un.second.first = max(r1.second.first, r2.second.first);
    un.second.second = min(r1.second.second, r2.second.second);
    long long res = ((long long)r1.first.second - r1.first.first + 1) *
                    ((long long)r1.second.second - r1.second.first + 1);
    res += ((long long)r2.first.second - r2.first.first + 1) *
           ((long long)r2.second.second - r2.second.first + 1);
    long long unar = ((long long)un.first.second - un.first.first + 1) *
                     ((long long)un.second.second - un.second.first + 1);
    if (un.first.second - un.first.first < 0 ||
        un.second.second - un.second.first < 0)
      unar = 0;
    cout << (long long)n * m - (res - unar) << endl;
  }
  return 0;
}

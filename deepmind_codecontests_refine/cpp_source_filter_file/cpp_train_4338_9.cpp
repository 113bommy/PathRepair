#include <bits/stdc++.h>
using namespace std;
vector<long long> s, e;
int main() {
  long long n, m, s1, e1, v, x, q, x1, x2, y1, y2;
  cin >> n >> m >> s1 >> e1 >> v;
  long long ss = s1;
  long long es = e1;
  while (s1--) cin >> x, s.push_back(x);
  while (e1--) cin >> x, e.push_back(x);
  cin >> q;
  while (q--) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      cout << abs(y1 - y2) << endl;
      return 0;
    }
    long long sum = 100000000000000;
    if (ss) {
      long long l = lower_bound(s.begin(), s.end(), y1) - s.begin();
      long long r = min(l + 3, ss - 1);
      l = max(0LL, l - 3);
      for (l = l; l <= r; l++)
        sum = min(sum, abs(y1 - s[l]) + abs(y2 - s[l]) + abs(x1 - x2));
      l = lower_bound(s.begin(), s.end(), y2) - s.begin();
      r = min(l + 3, ss - 1);
      l = max(0LL, l - 3);
      for (l = l; l <= r; l++)
        sum = min(sum, abs(y1 - s[l]) + abs(y2 - s[l]) + abs(x1 - x2));
    }
    if (es) {
      long long l = lower_bound(e.begin(), e.end(), y2) - e.begin();
      long long r = min(l + 3, es - 1);
      l = max(0LL, l - 3);
      for (l = l; l <= r; l++)
        sum = min(sum, abs(y1 - e[l]) + abs(y2 - e[l]) +
                           ((long long)(abs(x1 - x2)) + v - 1) / v);
      l = lower_bound(e.begin(), e.end(), y1) - e.begin();
      r = min(l + 3, es - 1);
      l = max(0LL, l - 3);
      for (l = l; l <= r; l++)
        sum = min(sum, abs(y1 - e[l]) + abs(y2 - e[l]) +
                           ((long long)(abs(x1 - x2)) + v - 1) / v);
    }
    cout << sum << endl;
  }
}

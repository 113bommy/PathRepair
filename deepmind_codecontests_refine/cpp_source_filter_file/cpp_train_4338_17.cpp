#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, cl, ce, v;
  cin >> n >> m >> cl >> ce >> v;
  long long int l[cl], e[ce];
  for (int i = 0; i < cl; i++) cin >> l[i];
  for (int i = 0; i < ce; i++) cin >> e[i];
  int q;
  cin >> q;
  while (q--) {
    long long int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      cout << abs(y1 - y2);
      continue;
    }
    long long int ans1 = LLONG_MAX, ans2 = LLONG_MAX, ans3 = LLONG_MAX,
                  ans4 = LLONG_MAX;
    long long int st1 = (lower_bound(l, l + cl, y1) - l);
    long long int st2 = st1 - 1;
    if (st1 != cl) ans1 = abs(y1 - l[st1]) + abs(x1 - x2) + abs(y2 - l[st1]);
    if (st2 != -1) ans2 = abs(y1 - l[st2]) + abs(x1 - x2) + abs(y2 - l[st2]);
    long long int st3 = (lower_bound(e, e + ce, y1) - e);
    long long int st4 = st3 - 1;
    if (st3 != ce)
      ans3 = abs(y1 - e[st3]) + (long long int)ceil(abs(x1 - x2) / (double)v) +
             abs(y2 - e[st3]);
    if (st4 != -1)
      ans4 = abs(y1 - e[st4]) + (long long int)ceil(abs(x1 - x2) / (double)v) +
             abs(y2 - e[st4]);
    cout << min(min(ans1, ans2), min(ans3, ans4)) << endl;
  }
  return 0;
}

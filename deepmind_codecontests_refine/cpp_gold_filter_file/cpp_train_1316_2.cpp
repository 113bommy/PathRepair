#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, s, e, v;
  cin >> n >> m >> s >> e >> v;
  long long st[s], ele[e];
  for (long long i = 0; i < s; i++) cin >> st[i];
  for (long long i = 0; i < e; i++) cin >> ele[i];
  long long q;
  cin >> q;
  while (q--) {
    long long x1, x2, y1, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    long long ans1, ans2, ans3, ans4;
    ans1 = ans2 = ans3 = ans4 = 1e18;
    long long x = lower_bound(st, st + s, x1) - st;
    if (x < s) {
      ans1 = abs(st[x] - x1) + abs(y2 - y1) + abs(x2 - st[x]);
    }
    x = lower_bound(st, st + s, x1) - st - 1;
    if (x >= 0) {
      ans1 = min(ans1, abs(st[x] - x1) + abs(y2 - y1) + abs(x2 - st[x]));
    }
    x = lower_bound(ele, ele + e, x1) - ele;
    if (x < e) {
      ans2 = abs(ele[x] - x1) +
             (long long)ceil(((double)abs(y2 - y1)) / (double)v) +
             abs(x2 - ele[x]);
    }
    x = lower_bound(ele, ele + e, x1) - ele - 1;
    if (x >= 0) {
      ans2 = min(ans2, abs(ele[x] - x1) +
                           (long long)ceil(((double)abs(y2 - y1)) / (double)v) +
                           abs(x2 - ele[x]));
    }
    if (y1 == y2) ans1 = min(ans1, abs(x2 - x1));
    cout << min(ans1, ans2) << "\n";
  }
}

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
using namespace std;
long long n, pos[300005], a[300005];
vector<pair<long long, long long> > ans;
void change(long long x, long long y) {
  ans.push_back(make_pair(x, y));
  long long ele1 = a[x];
  long long ele2 = a[y];
  pos[ele2] = x;
  pos[ele1] = y;
  swap(a[x], a[y]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long i;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (i = 1; i <= n; i++) {
    if (i == pos[i]) continue;
    long long x = pos[i];
    if (abs(x - i) >= (n / 2)) {
      change(i, x);
    } else if (x <= n / 2 && abs(i - n) < n / 2) {
      change(n, x);
      change(n, 1);
      change(i, 1);
      change(x, n);
      change(n, 1);
    } else if (x <= n / 2 && abs(i - n) >= (n / 2)) {
      change(x, n);
      change(n, i);
      change(x, n);
    } else if (x > (n / 2) && abs(i - 1) < n / 2) {
      change(1, x);
      change(1, n);
      change(i, n);
      change(1, x);
      change(x, n);
    } else {
      change(x, 1);
      change(1, i);
      change(x, 1);
    }
  }
  cout << ans.size() << "\n";
  for (i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
  return 0;
}

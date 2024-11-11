#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int r = 1;
  x = x % p;
  while (y) {
    if (y & 1) r = r * x % p;
    y = y >> 1;
    x = x * x % p;
  }
  return r;
}
const int N = 2e3 + 9;
struct node {
  vector<pair<long long int, long long int> > a;
};
node ar[N][10];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      if (ar[i][x].a.size() == 2) ar[i][x].a.pop_back();
      ar[i][x].a.push_back({i, j});
    }
  }
  map<pair<int, int>, int> mp;
  int lt, x;
  cin >> lt;
  int ans = 0;
  for (int i = 0; i < s - 1; i++) {
    cin >> x;
    if (mp[{lt, x}] || mp[{lt, x}]) continue;
    for (int i = 1; i <= n; i++)
      if (ar[i][x].a.size() && ar[i][lt].a.size())
        for (int j = i; j <= n; j++) {
          pair<int, int> aa, bb;
          if (ar[i][lt].a.size() >= 1 && ar[j][x].a.size() >= 2)
            aa = ar[i][lt].a[0], bb = ar[j][x].a[1],
            ans =
                max(ans, abs(aa.first - bb.first) + abs(aa.second - bb.second));
          if (ar[i][lt].a.size() >= 2 && ar[j][x].a.size() >= 1)
            aa = ar[i][lt].a[1], bb = ar[j][x].a[0],
            ans =
                max(ans, abs(aa.first - bb.first) + abs(aa.second - bb.second));
          if (ar[i][lt].a.size() >= 1 && ar[j][x].a.size() >= 1)
            aa = ar[i][lt].a[0], bb = ar[j][x].a[0],
            ans =
                max(ans, abs(aa.first - bb.first) + abs(aa.second - bb.second));
          if (ar[i][lt].a.size() >= 2 && ar[j][x].a.size() >= 2)
            aa = ar[i][lt].a[1], bb = ar[j][x].a[1],
            ans =
                max(ans, abs(aa.first - bb.first) + abs(aa.second - bb.second));
          swap(x, lt);
          if (ar[i][lt].a.size() >= 1 && ar[j][x].a.size() >= 2)
            aa = ar[i][lt].a[0], bb = ar[j][x].a[1],
            ans =
                max(ans, abs(aa.first - bb.first) + abs(aa.second - bb.second));
          if (ar[i][lt].a.size() >= 2 && ar[j][x].a.size() >= 1)
            aa = ar[i][lt].a[1], bb = ar[j][x].a[0],
            ans =
                max(ans, abs(aa.first - bb.first) + abs(aa.second - bb.second));
          if (ar[i][lt].a.size() >= 1 && ar[j][x].a.size() >= 1)
            aa = ar[i][lt].a[0], bb = ar[j][x].a[0],
            ans =
                max(ans, abs(aa.first - bb.first) + abs(aa.second - bb.second));
          if (ar[i][lt].a.size() >= 2 && ar[j][x].a.size() >= 2)
            aa = ar[i][lt].a[1], bb = ar[j][x].a[1],
            ans =
                max(ans, abs(aa.first - bb.first) + abs(aa.second - bb.second));
          swap(x, lt);
        }
    mp[{lt, x}] = mp[{lt, x}] = 1;
    lt = x;
  }
  cout << ans << '\n';
}

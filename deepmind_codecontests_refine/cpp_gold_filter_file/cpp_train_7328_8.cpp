#include <bits/stdc++.h>
using namespace std;
map<pair<long long, int>, pair<long long, int> > mp;
pair<long long, int> cal(long long n, int x) {
  if (n == 0) return make_pair(0, 0);
  if (n < 10) return make_pair(1, max(0, (int)(x - n)));
  pair<long long, int> now = make_pair(n, x);
  if (mp.count(now)) return mp[now];
  pair<long long, int> ans = make_pair(0, 0);
  long long ten = 1;
  while (ten <= n / 10) ten *= 10;
  while (true) {
    int df = n / ten;
    int nx = max(df, x);
    pair<long long, int> cur = cal(n % ten, nx);
    ans.first += cur.first;
    n -= n % ten;
    if (cur.second > 0)
      n -= cur.second;
    else if (nx > 0)
      n -= nx, ++ans.first;
    if (df == 0) break;
  }
  ans.second = -n;
  mp[now] = ans;
  return ans;
}
int main() {
  long long n;
  cin >> n;
  cout << cal(n, 0).first << endl;
  return 0;
}

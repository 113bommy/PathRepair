#include <bits/stdc++.h>
using namespace std;
struct __timestamper {};
int solve(vector<int> rs, vector<int> bs, int l, int r) {
  if (l != -1) {
    rs.insert(rs.begin(), l);
    bs.insert(bs.begin(), l);
  }
  if (r != -1) {
    rs.insert(rs.end(), r);
    bs.insert(bs.end(), r);
  }
  int ans = 0;
  int mr = 0, mb = 0;
  for (int i = 1; i < (int)rs.size(); i++) {
    int d = rs[i] - rs[i - 1];
    ans += d;
    mr = max(mr, d);
  }
  for (int i = 1; i < (int)bs.size(); i++) {
    int d = bs[i] - bs[i - 1];
    ans += d;
    mb = max(mb, d);
  }
  if (l != -1 && r != -1 && mr + mb > r - l) {
    ans += r - l - mr - mb;
  };
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> x(n);
  vector<char> c(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %c", &x[i], &c[i]);
  }
  int pg = -1;
  vector<int> rs;
  vector<int> bs;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] == 'G') {
      ans += solve(rs, bs, pg, x[i]);
      rs.clear();
      bs.clear();
      pg = x[i];
    } else if (c[i] == 'B') {
      bs.push_back(x[i]);
    } else {
      rs.push_back(x[i]);
    }
  }
  ans += solve(rs, bs, pg, -1);
  printf("%d\n", ans);
  return 0;
}

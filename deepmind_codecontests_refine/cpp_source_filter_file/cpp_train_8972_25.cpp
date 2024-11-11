#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<long long, int> > q;
vector<int> l, r, ans;
void f() { fflush(stdout); }
long long t1(int i, int j, int k) {
  printf("1 %d %d %d\n", i, j, k);
  f();
  long long sum;
  scanf("%I64d", &sum);
  return sum;
}
int t2(int i, int j, int k) {
  printf("2 %d %d %d\n", i, j, k);
  f();
  int s;
  scanf("%d", &s);
  return s;
}
int main() {
  scanf("%d", &n);
  int eg = 2;
  for (int i = 3; i <= n; ++i)
    if (t2(1, eg, i) < 0) eg = i;
  for (int i = 2; i <= n; ++i) {
    if (i == eg) continue;
    q.push_back(pair<long long, int>(t1(1, eg, i), i));
  }
  sort(q.begin(), q.end());
  int mx = q.back().second;
  for (auto v : q) {
    if (v.second == mx) continue;
    if (t1(1, mx, v.second) < 0)
      r.push_back(v.second);
    else
      l.push_back(v.second);
  }
  reverse(l.begin(), l.end());
  ans.push_back(1);
  ans.push_back(eg);
  for (int v : r) ans.push_back(v);
  ans.push_back(mx);
  for (int v : l) ans.push_back(v);
  printf("%d", 0);
  for (int v : ans) printf(" %d", v);
  puts("");
  return 0;
}

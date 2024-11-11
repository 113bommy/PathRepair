#include <bits/stdc++.h>
using namespace std;
const bool testcases = 1;
unsigned long long int logn(unsigned long long int n,
                            unsigned long long int r) {
  return (n > r - 1) ? 1 + logn(n / r, r) : 0;
}
int powmod(long long int x, unsigned long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
vector<int> garr(200005, 0);
vector<int> res;
void make_st(int k) {
  for (int i = 1; i <= k; ++i) garr[i] = i;
}
int root_st(int i) {
  while (garr[i] != i) garr[i] = garr[garr[i]], i = garr[i];
  return i;
}
void union_st(vector<int>& size_st, int a, int b) {
  a = root_st(a);
  b = root_st(b);
  if (a != b) {
    if (size_st[a] < size_st[b]) swap(a, b);
    garr[b] = a;
    size_st[a] += size_st[b];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> k;
  int n;
  cin >> n;
  make_st(k);
  vector<int> size_st(k + 1, 1);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    union_st(size_st, x, y);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    if (root_st(x) == root_st(y)) size_st[root_st(x)] = 0;
  }
  for (int i = 1; i <= n; ++i)
    if (garr[i] == i) res.push_back(i);
  int ans = 0;
  for (auto i = res.begin(); i != res.end(); ++i) {
    int mn = size_st[root_st(*i)];
    if (mn > ans) ans = mn;
  }
  cout << ans;
  return 0;
}

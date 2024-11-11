#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 15;
const int mod = 998244353;
int add(int x, int y) {
  int ret = (x + y) % mod;
  ret = (ret + mod) % mod;
  return ret;
}
int mul(int x, int y) {
  long long ret = x;
  ret *= y;
  ret %= mod;
  ret = (ret + mod) % mod;
  return (int)ret;
}
pair<int, int> in[N];
int per[N];
int get(int n) {
  int tmp = 1;
  for (int i = 0; i < n; ++i) {
    swap(in[i].first, in[i].second);
  }
  sort(in, in + n);
  for (int i = 0; i < n;) {
    int j;
    for (j = i; j < n; ++j) {
      if (in[j].first != in[i].first) {
        break;
      }
    }
    tmp = mul(tmp, per[j - i]);
    i = j;
  }
  return tmp;
}
void solve() {
  int n;
  per[0] = 1;
  scanf("%d", &n);
  for (int i = 1; i < N; ++i) {
    per[i] = mul(per[i - 1], i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &in[i].first, &in[i].second);
  }
  int ret = per[n];
  int tmp = 1;
  sort(in, in + n);
  bool g = true;
  int maxi = in[0].second;
  for (int i = 1; i < n; ++i) {
    if (maxi > in[i].second) {
      g = false;
      break;
    }
    maxi = max(maxi, in[i].second);
  }
  int rr = 0;
  if (g) {
    int l = 0;
    int d = 1;
    while (l < n) {
      int r = l + 1;
      while (r < n && in[l].first == in[r].first) ++r;
      map<int, int> m;
      for (int i = l; i < r; ++i) ++m[in[i].second];
      for (auto p : m) d = mul(d, per[p.second]);
      l = r;
    }
    rr = -d;
  }
  int v = add(get(n), get(n));
  rr = add(v, rr);
  ret = add(ret, -rr);
  printf("%d\n", ret);
}
int main(void) { solve(); }

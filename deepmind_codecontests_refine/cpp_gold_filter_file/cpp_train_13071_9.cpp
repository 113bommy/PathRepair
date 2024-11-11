#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int bit[200005];
void update(int, int);
int query(int);
int nr(int, int);
int main() {
  int i, j, n, a;
  ll ans, sum;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> a;
    update(a, 1);
  }
  for (ans = 0, i = 1; i < 200005; ++i)
    if (nr(i, i)) {
      for (sum = 0, j = i; j < 200005; j += i) {
        sum += 1LL * j * nr(j, j + i - 1);
      }
      if (sum > ans) ans = sum;
    }
  cout << ans << '\n';
  return 0;
}
void update(int pos, int val) {
  for (; pos < 200005; pos += pos & -pos) bit[pos] += val;
}
int query(int pos) {
  int res;
  for (res = 0; pos; pos &= pos - 1) res += bit[pos];
  return res;
}
int nr(int a, int b) {
  if (b >= 200005) b = 200005 - 1;
  return query(b) - query(a - 1);
}

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const int N = 5e4 + 5;
int x;
int mpow(long long a, int b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % x;
    a = (a * a) % x;
    b >>= 1;
  }
  return ans;
}
int mul(int a, int b) { return (long long)(a * b) % MOD; }
int cd[100];
map<pair<int, int>, int> memo;
int get(int b, int k) {
  if (b == 0) return (k == 1) ? 1 : 0;
  if (b == 1) return cd[k];
  if (memo.find({b, k}) != memo.end()) return memo[pair<int, int>(b, k)];
  int ret = 0;
  int bb = b / 2, fb = b - b / 2;
  int pb = mpow(10, bb);
  for (int f = 0; f < x; ++f) {
    int fk = (f * pb) % x;
    int bk = (k - fk + x) % x;
    ret = (ret + mul(get(fb, f), get(bb, bk))) % MOD;
  }
  memo.insert(make_pair(pair<int, int>(b, k), ret));
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, b, k;
  cin >> n >> b >> k >> x;
  for (int i = 0, num; i < n; ++i) {
    cin >> num;
    ++cd[num % x];
  }
  cout << get(b, k) << "\n";
  return 0;
}

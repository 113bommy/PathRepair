#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000009, MAX_N = 3000010;
long long fib[MAX_N];
int n, m;
void update(vector<long long>& tree, long long pos, long long val) {
  while (pos < n) {
    tree[pos] = (tree[pos] + val) % MOD;
    pos += pos & -pos;
  }
}
long long sum(vector<long long>& tree, long long pos) {
  long long res = 0;
  while (pos) {
    res = (res + tree[pos]) % MOD;
    pos &= pos - 1;
  }
  return res;
}
int main() {
  cin.tie(0), cout.tie(0);
  ios_base::sync_with_stdio(0);
  fib[0] = fib[1] = 1;
  for (long long i = 2; i < MAX_N; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
  }
  cin >> n >> m;
  vector<long long> t1(MAX_N), t2(MAX_N), t3(MAX_N);
  for (long long i = 1, num; i <= n; i++) {
    cin >> num;
    update(t3, i, num);
  }
  for (long long i = 0, type, l, r; i < m; i++) {
    cin >> type >> l >> r;
    if (type == 1) {
      int s = (l & 1) ? -1 : 1;
      update(t1, l, fib[l] * s);
      update(t2, l, fib[l + 1] * -s);
      update(t3, l, -1);
      update(t1, r, fib[l] * -s);
      update(t2, r, fib[l + 1] * s);
      update(t3, r, fib[r - l + 2]);
    } else {
      l--;
      long long sum1 =
          sum(t1, l) * fib[l + 4] + sum(t2, l) * fib[l + 3] + sum(t3, l);
      long long sum2 =
          sum(t1, r) * fib[r + 4] + sum(t2, r) * fib[r + 3] + sum(t3, r);
      long long ans = (sum2 - sum1);
      ans = ((ans % MOD) + MOD) % MOD;
      cout << ans << "\n";
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1100100;
const long long mod = 1000000007;
struct entry {
  int cnt, last;
  long long nprev;
};
map<int, entry> v;
long long times(long long seq, long long total) {
  return total >= seq ? (total - seq + 1) % mod : 0;
}
int main() {
  cin.sync_with_stdio(false);
  int n, k;
  long long l, rep, rest;
  cin >> n >> l >> k;
  rep = l / n;
  rest = l % n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    v[tmp].cnt++;
    v[tmp].last += i < rest;
  }
  long long total = l, last = 0;
  for (auto &e : v) {
    e.second.nprev = last + e.second.cnt;
    last = e.second.nprev;
  }
  for (int x = 2; x <= k && x <= rep + 1; x++) {
    long long next = 0;
    for (auto &e : v) {
      auto &nr = e.second;
      long long how =
          (nr.last * times(x, rep + 1) + (nr.cnt - nr.last) * times(x, rep)) %
          mod;
      how = (how * nr.nprev) % mod;
      total = (total + how) % mod;
      next = (next + (nr.nprev * nr.cnt) % mod) % mod;
      nr.nprev = next;
    }
  }
  cout << total;
}

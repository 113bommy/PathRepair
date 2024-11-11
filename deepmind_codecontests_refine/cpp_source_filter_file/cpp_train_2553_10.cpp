#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
long long n, m, k, answer;
long long ente[MAXN], p[MAXN], have[MAXN];
vector<long long> divi[MAXN];
long long po(long long v, long long u) {
  return u ? (po(v * v % MOD, u >> 1) * (u & 1 ? v : 1) % MOD) : 1;
}
void upt(int id) {
  answer += (p[id] * (ente[have[id] + 1] - ente[have[id]])) % MOD;
  answer %= MOD;
  have[id]++;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  for (int i = 2; i < MAXN; i++)
    if (divi[i].empty())
      for (int j = i; j < MAXN; j += i) divi[j].push_back(i);
  for (int i = 1; i < MAXN; i++) {
    long long local = i;
    for (auto j : divi[i]) {
      local *= j - 1;
      local /= j;
    }
    p[i] = local;
  }
  cin >> n >> k >> m;
  ente[k] = 1;
  for (int i = k + 1; i < MAXN; i++)
    ente[i] = (((ente[i - 1] * i) % MOD) * po(i - k, MOD - 2)) % MOD;
  for (int i = 0; i < n + m; i++) {
    long long val;
    cin >> val;
    for (int j = 1; j * j <= val; j++)
      if (val % j == 0) {
        upt(j);
        if (j * j != val) upt(val / j);
      }
    if (i >= n) cout << answer << '\n';
  }
  cin >> n;
  return 0;
}

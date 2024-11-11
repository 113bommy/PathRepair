#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2050;
vector<long long> L[MAXN];
bool mk[MAXN];
vector<long long> vect;
const long long MOD = 1e9 + 7;
void DFS(long long nodo, long long lvl) {
  mk[nodo] = true;
  for (auto v : L[nodo]) {
    if (!mk[v]) {
      DFS(v, lvl + 1);
    } else if (v == 1) {
      vect.push_back(lvl + 1);
    }
  }
}
long long dp[2 * MAXN];
long long temp[2 * MAXN];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long N, M;
  cin >> N >> M;
  for (long long i = 0; i < M; i++) {
    long long a, b;
    cin >> a >> b;
    L[a].push_back(b);
    L[b].push_back(a);
  }
  DFS(1, 0);
  long long sz = vect.size() / 2;
  vector<long long> tpp = vect;
  vect.clear();
  for (long long i = 0; i < tpp.size(); i++) {
    if (tpp[i] == 2 && sz) {
      sz--;
      continue;
    }
    vect.push_back(tpp[i]);
  }
  map<long long, long long> mp;
  for (auto x : vect) {
    mp[x]++;
  }
  vector<pair<long long, long long>> vvv;
  for (auto x : mp) {
    vvv.push_back(x);
  }
  long long res = 0;
  for (auto x : vvv) {
    bool flag = true;
    for (long long i = 0; i < 2 * MAXN; i++) {
      dp[i] = temp[i] = 0;
    }
    dp[MAXN] = 1;
    for (long long i = 0; i < vect.size(); i++) {
      if (vect[i] == x.first && flag) {
        flag = false;
        continue;
      }
      for (long long j = 0; j < 2 * MAXN; j++) {
        temp[j] = dp[j];
        if (j - vect[i] >= 0) temp[j] += dp[j - vect[i]];
        if (j + vect[i] < 2 * MAXN) temp[j] += dp[j + vect[i]];
        temp[j] %= MOD;
      }
      for (long long j = 0; j < 2 * MAXN; j++) {
        dp[j] = temp[j];
      }
    }
    long long sum = 0;
    for (long long i = 0; i < 2 * MAXN; i++) {
      long long val = abs(i - MAXN);
      if (x.first - 2 >= val) {
        sum = (sum + dp[i] * 2) % MOD;
      }
    }
    sum = (sum)*x.second % MOD;
    res = (res + sum) % MOD;
  }
  for (auto x : vvv) {
    bool flag = true;
    for (long long i = 0; i < 2 * MAXN; i++) {
      dp[i] = temp[i] = 0;
    }
    dp[MAXN] = 1;
    for (long long i = 0; i < vect.size(); i++) {
      if (vect[i] == x.first && flag) {
        flag = false;
        continue;
      }
      for (long long j = 0; j < 2 * MAXN; j++) {
        temp[j] = 0;
        if (j - vect[i] >= 0) temp[j] += dp[j - vect[i]];
        if (j + vect[i] < 2 * MAXN) temp[j] += dp[j + vect[i]];
        temp[j] %= MOD;
      }
      for (long long j = 0; j < 2 * MAXN; j++) {
        dp[j] = temp[j];
      }
    }
    long long sum = 0;
    for (long long i = 0; i < 2 * MAXN; i++) {
      long long val = abs(i - MAXN);
      if (x.first == val - 1) {
        sum = (sum + dp[i] * 2) % MOD;
      }
    }
    sum = (sum)*x.second % MOD;
    res = (res + sum) % MOD;
  }
  for (long long i = 0; i < 2 * MAXN; i++) {
    dp[i] = temp[i] = 0;
  }
  dp[MAXN] = 1;
  for (long long i = 0; i < vect.size(); i++) {
    for (long long j = 0; j < 2 * MAXN; j++) {
      temp[j] = 0;
      if (j - vect[i] >= 0) temp[j] += dp[j - vect[i]];
      if (j + vect[i] < 2 * MAXN) temp[j] += dp[j + vect[i]];
      temp[j] %= MOD;
    }
    for (long long j = 0; j < 2 * MAXN; j++) {
      dp[j] = temp[j];
    }
  }
  cout << (res % MOD + dp[MAXN]) % MOD << '\n';
  return 0;
}

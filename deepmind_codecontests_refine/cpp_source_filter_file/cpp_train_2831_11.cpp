#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long dp[1 << 20];
pair<long long, long long> P[1 << 20];
long long sentinal[20][20];
long long arr[20][1 << 20];
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a > b)
    return b;
  else
    return a;
}
long long foo(long long mask) {
  if (mask == 0) return 0;
  if (dp[mask] != -10000000000000000) return dp[mask];
  long long pos = __builtin_popcount(mask);
  long long minm = 10000000000000000;
  for (long long j = 0; j < m; ++j) {
    if (!(mask & (1 << j))) continue;
    long long contribution = arr[j][mask];
    minm = min(foo(mask ^ (1 << j)) + contribution * pos, minm);
  }
  dp[mask] = minm;
  return minm;
}
void foo1(long long pos, long long mask) {
  if (arr[pos][mask] != -10000000000000000) return;
  if (P[mask].first == P[mask].second) {
    arr[pos][mask] = 0;
    for (long long i = 0; i < 20; ++i) {
      if (mask & (1 << i)) continue;
      arr[pos][mask] -= sentinal[pos][i];
    }
    return;
  }
  if (P[mask].first == pos) {
    foo1(pos, mask ^ (1 << P[mask].second));
    long long ui = sentinal[pos][P[mask].second];
    ui *= 2;
    arr[pos][mask] = ui + arr[pos][mask ^ (1 << P[mask].second)];
  } else {
    foo1(pos, mask ^ (1 << P[mask].first));
    long long ui = sentinal[pos][P[mask].first];
    ui *= 2;
    arr[pos][mask] = ui + arr[pos][mask ^ (1 << P[mask].first)];
  }
}
int main() {
  for (long long i = 1; i < (1 << 20); ++i) {
    P[i].first = -1;
    P[i].second = 30;
    for (long long j = 25; j >= 0; --j) {
      if (i & (1 << j)) {
        P[i].first = max(P[i].first, j);
        P[i].second = min(P[i].second, j);
      }
    }
  }
  for (long long i = 0; i < (1 << 20); ++i) {
    dp[i] = -10000000000000000;
  }
  for (long long i = 0; i < 20; ++i) {
    for (long long j = 0; j < 20; ++j) {
      sentinal[i][j] = 0;
    }
  }
  cin >> n >> m;
  string s;
  cin >> s;
  for (long long i = 0; i < n - 1; ++i) {
    sentinal[s[i] - 'a'][s[i + 1] - 'a'] += 1;
    sentinal[s[i + 1] - 'a'][s[i] - 'a'] += 1;
  }
  for (long long i = 0; i < 10; ++i) {
    for (long long j = 0; j < (1 << 20); ++j) {
      arr[i][j] = -10000000000000000;
    }
  }
  for (long long i = 0; i < 20; ++i) {
    for (long long j = 1; j < (1 << 20); ++j) {
      if (j & (1 << i)) foo1(i, j);
    }
  }
  cout << foo((1 << m) - 1);
  return 0;
}

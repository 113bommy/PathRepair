#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e % 2)
    return ((b * power((b) * (b), (e - 1) / 2)));
  else
    return power((b) * (b), e / 2);
}
long long modpower(long long b, long long e, long long q) {
  long long MOD = q;
  if (e == 0) return 1;
  if (e % 2)
    return ((b % MOD) * modpower((b % MOD) * (b % MOD), (e - 1) / 2, q)) % MOD;
  else
    return modpower((b % MOD) * (b % MOD), e / 2, q) % MOD;
}
void dpv(vector<long long> v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << '\n';
}
void dpv(vector<pair<long long, long long> > v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << '\n';
  }
}
void dpv(set<long long> v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << '\n';
}
long long n, m;
long long a[300005][10];
long long a1, a2;
bool can(long long x) {
  vector<long long> mask(1 << m, -1);
  for (long long i = 0; i < n; i++) {
    long long cur = 0;
    for (long long j = 0; j < m; j++) {
      if (a[i][j] >= x) {
        cur ^= (1 << j);
      }
    }
    mask[cur] = i;
  }
  if (mask[(1 << m) - 1] != -1) {
    a1 = a2 = mask[(1 << m) - 1];
    return true;
  }
  for (long long i = 0; i < (1 << m); i++) {
    for (long long j = 0; j < (1 << m); j++) {
      if (mask[i] != -1 && mask[j] != -1 && ((i | j) == ((1 << m) - 1))) {
        a1 = mask[i];
        a2 = mask[j];
        return true;
      }
    }
  }
  return false;
}
void oblivious() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  long long l = 0, r = 1e9 + 43;
  while (r - l > 1) {
    long long x = (l + r) / 2;
    if (can(x)) {
      l = x;
    } else {
      r = x;
    }
  }
  cout << a1 + 1 << " " << a2 + 1 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    oblivious();
  }
  return 0;
}

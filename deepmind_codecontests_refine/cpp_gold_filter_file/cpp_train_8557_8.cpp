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
long long rand_int(long long l, long long r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<long long>(l, r)(gen);
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
  cout << endl;
}
void dpv(vector<pair<long long, long long> > v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}
void dpv(set<long long> v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}
long long ceil1(long long x, long long y) {
  long long r = x / y;
  if (x % y == 0) {
    return r;
  } else {
    return r + 1;
  }
}
long long count(long long x, long long d, long long n) {
  long long z = x;
  long long ans = 0;
  while (z < n) {
    if (n > z + d - 1) {
      ans += d;
    } else {
      ans += (n - z + 1);
    }
    z = z * 2;
    d = d * 2;
  }
  return ans;
}
bool oke(long long x, long long n, long long k) {
  long long ans = count(x, 2, n);
  return ans >= k;
}
bool oko(long long x, long long n, long long k) {
  long long ans = count(x, 1, n);
  return ans >= k;
}
void oblivious() {
  long long n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n << endl;
    return;
  } else if (k == n) {
    cout << 1 << endl;
    return;
  }
  long long l = 1, r = n;
  long long ans1 = 0;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (mid & 1) {
      mid++;
    }
    if (oke(mid, n, k)) {
      ans1 = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  long long ans2 = 0;
  l = 1;
  r = n;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (!(mid & 1)) {
      mid++;
    }
    if (oko(mid, n, k)) {
      ans2 = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << max(ans1, ans2) << endl;
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

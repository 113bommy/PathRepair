#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
long long int MOD = 1000000007;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= 1000000009;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000009;
    a = a * a % 1000000009;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int add(long long int a, long long int b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}
long long int mul(long long int a, long long int b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
long long int sub(long long int a, long long int b) {
  return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
long long int binpow(long long int x, long long int y) {
  long long int z = 1;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}
map<int, int> graph[200005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 0; i < m; i++) {
    long long int a, b;
    cin >> a >> b;
    graph[a][-b]++;
    graph[b][-a]++;
  }
  long long int count = 0;
  for (int i = 1; i <= n; i++) {
    long long int x = 0;
    for (auto u : graph[i]) {
      x = -u.first;
      break;
    }
    if (x < i) {
      count++;
    }
  }
  long long int q;
  cin >> q;
  while (q--) {
    long long int ask;
    cin >> ask;
    if (ask == 3) {
      cout << count << endl;
    } else if (ask == 1) {
      long long int a, b;
      cin >> a >> b;
      long long int x = 0;
      long long int y = 0;
      for (auto u : graph[a]) {
        x = -u.first;
        break;
      }
      for (auto u : graph[b]) {
        y = -u.first;
        break;
      }
      graph[a][-b]++;
      graph[b][-a]++;
      if (b > a && x < a) {
        count--;
      }
      if (a > b && y < b) {
        count--;
      }
    } else if (ask == 2) {
      long long int a, b;
      cin >> a >> b;
      long long int x = 0;
      long long int y = 0;
      graph[a].erase(-b);
      graph[b].erase(-a);
      for (auto u : graph[a]) {
        x = -u.first;
        break;
      }
      for (auto u : graph[b]) {
        y = -u.first;
        break;
      }
      if (x < a && b > a) {
        count++;
      }
      if (y < b && a > b) {
        count++;
      }
    }
  }
}

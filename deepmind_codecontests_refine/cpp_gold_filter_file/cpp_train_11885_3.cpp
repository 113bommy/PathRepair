#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b) * b);
}
long long int bigmod(long long int a, long long int b, long long int mod) {
  b %= (mod - 1);
  long long int result = 1ll;
  while (b > 0ll) {
    if (b & 1ll) result = result * a % mod;
    a = a * a % mod;
    b >>= 1ll;
  }
  return result;
}
long long int inverse(long long int a, long long int M) {
  if (gcd(a, M) == 1) return bigmod(a, M - 2, M) % M;
  return 1;
}
long long int ncr(long long int a, long long int b, long long int mod) {
  long long int x = max(a - b, b), ans = 1;
  for (long long int K = a, L = 1; K >= x + 1; K--, L++) {
    ans = ans * K % mod;
    ans = ans * inverse(L, mod) % mod;
  }
  return ans;
}
long long int prime(long long int n) {
  long long int cnt = 0;
  while (n % 2 == 0) {
    n /= 2;
    cnt++;
  }
  for (long long int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
    }
  }
  if (n > 1) cnt++;
  return cnt;
}
long long int fact(long long int n, long long int mod) {
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) {
    res = (res % mod * i % mod) % mod;
  }
  return res;
}
void urmi() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
vector<long long int> v[200003];
bool vis[200003];
long long int bfs(int n) {
  vis[n] = true;
  long long int cnt = 1;
  queue<long long int> q;
  q.push(n);
  while (!q.empty()) {
    long long int u = q.front();
    q.pop();
    for (auto i : v[u]) {
      if (vis[i] == false) {
        vis[i] = true;
        cnt++;
        q.push(i);
      }
    }
  }
  return cnt;
}
vector<long long int> adj[300003];
long long int in[300003];
long long int out[300003];
long long int depth[300003];
long long int low[300003];
long long int timer, even;
vector<pair<long long int, long long int>> edge;
bool isbridge = false;
map<long long int, long long int> m1;
long long int d = 0;
void dfs(long long int n, long long int par) {
  vis[n] = true;
  for (auto i : v[n]) {
    if (i == par) {
      m1[par]++;
      d = max(d, m1[par]);
    } else if (!vis[i])
      dfs(i, n);
    else
      m1[i]++;
  }
}
long long int e, g, h, g1;
long long int check(long long int n, long long int m, long long int a[],
                    long long int b[]) {
  bool ok = false;
  for (long long int i = 0; i < m; i++) {
    if (a[i] == n || b[i] == n)
      d++;
    else {
      if (ok == false) {
        ok = true;
        g = a[i];
        h = b[i];
      }
      m1[a[i]]++;
      m1[b[i]]++;
      e = max(m1[a[i]], m1[b[i]]);
    }
  }
  return e;
}
long long int check(long long int n, long long int u, long long int m,
                    long long int a[], long long int b[]) {
  for (long long int i = 0; i < m; i++) {
    if (a[i] == n || b[i] == n)
      continue;
    else if (a[i] == u || b[i] == u)
      d++;
    else {
      m1[a[i]]++;
      m1[b[i]]++;
      e = max(m1[a[i]], m1[b[i]]);
    }
  }
  return e;
}
int main() {
  urmi();
  long long int t = 1;
  while (t--) {
    long long int n, m, m2;
    cin >> n >> m;
    m2 = m;
    long long int a[m], b[m];
    for (long long int i = 0; i < m; i++) {
      cin >> a[i] >> b[i];
    }
    long long int c = a[0], d1 = b[0];
    long long int e = check(c, m2, a, b);
    if (e == m - d) {
      cout << "YES" << '\n';
      return 0;
    } else {
      m -= d;
      d = 0;
      m1.clear();
      e = check(c, g, m2, a, b);
      if (d == m) {
        cout << "YES" << '\n';
        return 0;
      }
      d = 0;
      m1.clear();
      e = check(c, h, m2, a, b);
      if (d == m) {
        cout << "YES" << '\n';
        return 0;
      }
    }
    d = 0;
    m1.clear();
    e = check(d1, m2, a, b);
    m = m2;
    if (e == m - d) {
      cout << "YES" << '\n';
      return 0;
    } else {
      m -= d;
      d = 0;
      m1.clear();
      e = check(d1, g, m2, a, b);
      if (d == m) {
        cout << "YES" << '\n';
        return 0;
      }
      d = 0;
      m1.clear();
      e = check(d1, h, m2, a, b);
      if (d == m) {
        cout << "YES" << '\n';
        return 0;
      }
    }
    cout << "NO" << '\n';
  }
}

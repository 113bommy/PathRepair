#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1E9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int gcd_ex(long long int a, long long int b, long long int& x,
                     long long int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int g = gcd_ex(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}
long long int multi_mod_inv(long long int a, long long int m) {
  long long int x, y;
  long long int g = gcd_ex(a, m, x, y);
  if (g != 1) {
    return -1;
  }
  x = (x % m + m) % m;
  return x;
}
long long int mod_div(long long int a, long long int b, long long int m) {
  if (multi_mod_inv(b, m) != -1) {
    return (a % m * multi_mod_inv(b, m) % m) % m;
  } else {
    return -1;
  }
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
long long int power(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int p = power(a, n / 2);
  p = (p * p) % MOD;
  if (n % 2)
    return (p * a) % MOD;
  else
    return p % MOD;
}
vector<long long int> col(2 * 100000 + 1, 0);
vector<vector<long long int>> cycle;
vector<long long int> path;
void dfs(vector<long long int>& visited, vector<long long int>& a,
         long long int s) {
  col[s] = 1;
  path.push_back(s);
  long long int x = a[s];
  if (col[x] != 2) {
    if (col[x] == 1) {
      vector<long long int> c;
      long long int i = path.size() - 1;
      while (path[i] != x) {
        c.push_back(path[i]);
        i--;
      }
      c.push_back(x);
      cycle.push_back(c);
      col[x] = 2;
    } else {
      return dfs(visited, a, x);
    }
  }
  path.pop_back();
  col[s] = 2;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int test = 1;
  while (test--) {
    long long int n;
    cin >> n;
    vector<long long int> c(n + 1), a(n + 1);
    for (long long int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    for (long long int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<long long int> visited(n + 1, 0);
    for (long long int i = 1; i <= n; i++) {
      if (col[i] == 0) {
        dfs(visited, a, i);
      }
    }
    long long int ans = 0;
    for (auto x : cycle) {
      long long int cmin = 1E9;
      for (auto y : x) {
        cmin = min(cmin, c[y]);
      }
      ans += cmin;
    }
    cout << ans << endl;
  }
  return 0;
}

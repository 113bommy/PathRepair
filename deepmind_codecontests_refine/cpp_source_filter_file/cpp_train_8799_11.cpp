#include <bits/stdc++.h>
using namespace std;
bool primecheck(long long int a) {
  bool check = true;
  if (a == 1) return (false);
  for (long long int i = 2; i <= sqrt(a); i++) {
    if (a % i == 0) {
      check = false;
      break;
    }
  }
  return (check);
}
vector<long long int> primeFactors(long long int n) {
  vector<long long int> sol;
  bool once = false;
  while (n % 2 == 0) {
    if (!once) {
      sol.push_back(2);
      once = true;
    }
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    bool once = false;
    while (n % i == 0) {
      if (!once) {
        sol.push_back(i);
        once = true;
      }
      n = n / i;
    }
  }
  if (n > 2) {
    sol.push_back(n);
  }
  return (sol);
}
vector<long long int> printDivisors(long long int n) {
  vector<long long int> sol;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        sol.push_back(i);
      } else {
        sol.push_back(i);
        sol.push_back(n / i);
      }
    }
  }
  return (sol);
}
long long int digits(long long int a) { return (floor(log10(a)) + 1); }
long long int bits(long long int n) { return __builtin_popcount(n); }
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
void addEdge(vector<long long int> adj[], long long int u, long long int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
vector<long long int> path;
void dfs(long long int u, vector<long long int> adj[], vector<bool> &visited,
         long long int parent = -1) {
  visited[u] = true;
  path[u] = parent;
  for (long long int i = 0; i < adj[u].size(); i++) {
    if (visited[adj[u][i]] == false) {
      dfs(adj[u][i], adj, visited, u);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b, c, i, j, k, l, m, n, t, p;
  cin >> a >> b >> c;
  long long int arr[c];
  vector<long long int> pos(10000, -1);
  long long int max = 0;
  long long int zero = 0;
  for (i = 0; i < c; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
    if (i == 0) {
      zero = arr[i];
    }
    if (arr[i] > max) max = arr[i];
  }
  vector<long long int> items[a];
  long long int sum = 0;
  for (i = 0; i < a; i++) {
    for (j = 0; j < b; j++) {
      cin >> m;
      items[i].push_back(m);
      sum += pos[m] + 1;
      for (k = 1; k <= max; k++) {
        if (pos[k] < m) {
          pos[k]++;
        }
      }
      pos[m] = 0;
      zero = m;
    }
  }
  cout << sum << "\n";
}

#include <bits/stdc++.h>
using namespace std;
vector<long long> pf;
vector<long long> d;
vector<long long> adj[200030];
vector<long long> dist;
bool nod[200030];
long long ceildiv(long long one, long long two) {
  if (one % two == 0) {
    return one / two;
  } else {
    return one / two + 1;
  }
}
void primeFactors(long long n) {
  while (n % 2 == 0) {
    pf.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      pf.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) {
    pf.push_back(n);
  }
}
long long power(long long n, long long pow, long long m) {
  if (pow == 0) return 1;
  if (pow % 2 == 0) {
    long long x = power(n, pow / 2, m);
    return (x * x) % m;
  } else
    return (power(n, pow - 1, m) * n) % m;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
bool permutation(long long arr[], long long n) {
  set<long long> hash;
  long long maxEle = 0;
  for (long long i = 0; i < n; i++) {
    hash.insert(arr[i]);
    maxEle = max(maxEle, arr[i]);
  }
  if (maxEle != n) {
    return false;
  }
  if (hash.size() * 1LL == n) {
    return true;
  }
  return false;
}
void divis(long long n) {
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      d.push_back(i);
      if (i * i != n) {
        d.push_back(n / i);
      }
    }
  }
  sort(d.begin(), d.end());
}
long long factorial(long long n, long long mod) {
  if (n > 1)
    return (n * factorial(n - 1, mod)) % mod;
  else
    return 1;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long checkPrimeNumber(long long n) {
  bool flag = false;
  for (long long i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      flag = true;
      break;
    }
  }
  return flag;
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (long long i = 0; i < (long long)v.size(); i++) res += char('0' + v[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto x : v) {
    if (!f) res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}
template <class A>
void write(A x) {
  cout << to_string(x);
}
template <class H, class... T>
void write(const H& h, const T&... t) {
  write(h);
  write(t...);
}
void print() { write("\n"); }
template <class H, class... T>
void print(const H& h, const T&... t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
void dfs(long long u) {
  nod[u] = true;
  for (auto x : adj[u]) {
    if (nod[x]) continue;
    nod[x] = true;
    dfs(x);
  }
}
void bfs(long long s) {
  dist.assign(200005, -1);
  queue<long long> q;
  dist[s] = 0;
  q.push(s);
  while (q.size()) {
    long long u = q.front();
    q.pop();
    for (long long v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b + c + d == 1) {
    if (a == 1) {
      print("Ya Tidak Tidak Tidak");
    }
    if (b == 1) {
      print("Tidak Ya Tidak Tidak");
    }
    if (c == 1) {
      print("Tidak Tidak Ya Tidak");
    }
    if (d == 1) {
      print("Tidak Tidak Tidak Ya");
    }
    return;
  }
  long long im = a + b;
  if (im % 2 == 0) {
    if (b > 0 || c > 0) {
      if (a > 0 || d > 0) {
        print("Tidak Tidak Ya Ya");
      } else {
        print("Tidak Tidak Ya Tidak");
      }
    } else {
      print("Tidak Tidak Tidak Ya");
    }
  } else {
    if (b > 0 || c > 0) {
      if (a > 0 || d > 0) {
        print("Ya Ya Tidak Tidak");
      } else {
        print("Tidak Ya Tidak Tidak");
      }
    } else {
      print("Ya Tidak Tidak Tidak");
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

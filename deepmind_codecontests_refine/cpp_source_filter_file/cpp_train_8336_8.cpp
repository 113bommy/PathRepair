#include <bits/stdc++.h>
using namespace std;
bool primes[1000000 + 1];
void sieve(long long int n) {
  primes[0] = false;
  primes[1] = false;
  for (long long int i{2}; i <= n; i++) {
    primes[i] = true;
  }
  for (long long int i{2}; i <= sqrt(n); i++) {
    if (primes[i] == true) {
      for (long long int j{2}; j * i <= n; j++) {
        primes[i * j] = false;
      }
    }
  }
}
bool comp(pair<int, int> &a, pair<int, int> &b) { return (a.first < b.first); }
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
long long int fastpow(long long base, long long n) {
  if (n == 0) return 1;
  if (n == 1) return base;
  long long halfn = fastpow(base, n / 2);
  if (n % 2 == 0)
    return (halfn * halfn);
  else
    return (((halfn * halfn)) * base);
}
void bfs(long long int s, vector<long long int> v[], bool vis[]) {
  queue<long long int> q;
  q.push(s);
  vis[s] = true;
  while (!q.empty()) {
    long long int a = q.front();
    q.pop();
    for (auto x : v[a]) {
      if (!vis[x]) {
        q.push(x);
        vis[x] = true;
      }
    }
  }
}
void dfs(long long int s, vector<long long int> v[], bool vis[]) {
  vis[s] = true;
  for (auto x : v[s]) {
    if (!vis[x]) {
      dfs(x, v, vis);
    }
  }
}
bool checksubsq(string s, long long int l, string t, long long int j) {
  for (long long int i{l}; i < s.size(); i++) {
    if (s[i] == t[j]) {
      if (j == t.size() - 1) {
        return true;
      } else {
        return checksubsq(s, i + 1, t, j + 1);
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  ;
  map<long long, long long> f;
  for (long long int i = 0; i < n; i++) {
    f[a[i]]++;
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    bool flag = false;
    for (long long int j = 0; j < 15; j++) {
      long long int x = fastpow(2, j);
      if (x >= a[i]) {
        if (f[x - a[i]]) {
          if (x - a[i] == a[i] && f[a[i]] == 1) {
          } else {
            flag = true;
            break;
          }
        }
      }
    }
    if (!flag) {
      f[a[i]]--;
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}

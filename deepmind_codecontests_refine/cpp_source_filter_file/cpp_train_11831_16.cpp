#include <bits/stdc++.h>
const long long mod = 1000000007;
using namespace std;
const int N = 2e5 + 5;
vector<int> e[N];
int vis[N], visi[N];
int pr[N];
bool comp(long long &a, long long &b) { return a > b; }
long long binpow(long long a, long long b, long long m) {
  if (a == 0) return a;
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long temp = binpow(a, b / 2, m) % m;
  if (b & 1) return (a * temp * temp) % m;
  return (temp * temp) % m;
}
int k = -1;
void dfs(int i, int p) {
  if (vis[i]) {
    k = i;
    return;
  }
  vis[i] = 1;
  for (auto j : e[i]) {
    if (j != p) {
      dfs(j, i);
    }
  }
  return;
}
void dfsi(int i, int p, int h) {
  if (visi[i]) return;
  visi[i] = 1;
  pr[i] = p;
  for (auto j : e[i]) {
    if (j != p) {
      if (j == h) {
        pr[j] = i;
        return;
      }
      dfsi(j, i, h);
    }
  }
  return;
}
long long nck(long long n, long long k) {
  long long g = 1;
  map<long long, long long> m;
  for (long long i = n - k + 1; i <= n; i++) {
    g *= i;
    for (long long j = 2; j <= k; j++) {
      if (m[j] == 0 && g % j == 0) {
        g /= j;
        m[j]++;
      }
    }
  }
  return g;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    string s;
    cin >> s;
    int g = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u' || s[i] == '0' || s[i] == '2' || s[i] == '4' ||
          s[i] == '6' || s[i] == '8')
        g++;
    }
    cout << g << endl;
  }
}

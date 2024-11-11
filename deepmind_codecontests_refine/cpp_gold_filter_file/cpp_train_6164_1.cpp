#include <bits/stdc++.h>
long long int min(long long int x, long long int y) { return (x < y) ? x : y; }
long long int max(long long int x, long long int y) { return (x > y) ? x : y; }
long long int fastexpo(long long int base, long long int power) {
  long long int res = 1;
  while (power) {
    if (power % 2 == 0) {
      base *= base;
      power /= 2;
    } else {
      res *= base;
      power--;
    }
  }
  return res;
}
long long int modexpo(long long int base, long long int power,
                      long long int mod) {
  long long int res = 1;
  while (power) {
    if (power % 2 == 0) {
      base = (base * base) % mod;
      power /= 2;
    } else {
      res = (base * res) % mod;
      power--;
    }
  }
  return res;
}
const long long int SN = 1e7;
bool prime[SN + 1];
void SEIVE(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  prime[0] = false;
  prime[1] = false;
}
using namespace std;
int x[26], par[200010];
int find(int n) {
  if (par[n] == n)
    return n;
  else
    return par[n] = find(par[n]);
}
void solve() {
  int n;
  cin >> n;
  for (long long int i = 0; i < n + 1; i++) par[i] = i;
  for (long long int i = 1; i < n + 1; i++) {
    string s;
    cin >> s;
    for (long long int j = 0; j < s.size(); j++) {
      if (!x[s[j] - 'a'])
        x[s[j] - 'a'] = i;
      else
        par[find(i)] = par[x[s[j] - 'a']];
    }
  }
  int ans = 0;
  for (long long int i = 1; i < n + 1; i++) {
    if (par[i] == i) ans++;
  }
  cout << ans;
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  solve();
}

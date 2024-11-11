#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
using ll = long long int;
using dl = double;
ll aarray[100000 + 10];
ll magic[501][501];
ll ar[200000 + 10];
ll ccount[2000000 + 1];
int main() {
  ios_base::sync_with_stdio(false);
  string ptr, str;
  ll m1, m2, m3, m4, i, j, n, k, m5, m, ta, t, flag, ans = INT_MAX;
  ll w1, w2, w3, w4, w5;
  vector<ll> dvi, cvi;
  set<ll> sc;
  bool primes[1000007];
  memset(primes, true, sizeof(primes));
  primes[0] = primes[1] = false;
  ll r1 = INT_MAX, r2 = INT_MAX, c2, c1, d1, d2;
  set<ll> sl;
  ll a, b, c, d;
  cin >> n;
  cin >> str;
  ll cnt = 0;
  for (i = 0; i < str.length(); i++) {
    if (str[i] == '<') {
      cnt++;
    } else
      break;
  }
  for (i = str.length() - 1; i >= 0; i--) {
    if (str[i] == '>') {
      cnt++;
    } else
      break;
  }
  cout << cnt << endl;
}

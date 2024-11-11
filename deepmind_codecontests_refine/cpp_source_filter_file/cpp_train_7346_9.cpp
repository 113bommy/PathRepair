#include <bits/stdc++.h>
using namespace std;
bool is_prime[1000001];
vector<long long> primes;
void seive() {
  long long maxN = 1000001;
  is_prime[0] = true;
  is_prime[1] = true;
  for (long long i = 2; i * i <= maxN; i++) {
    if (!is_prime[i]) {
      for (long long j = i * i; j <= maxN; j += i) is_prime[j] = true;
    }
  }
  for (long long i = 2; i <= maxN; i++) {
    if (!is_prime[i]) primes.push_back(i);
  }
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  long long q, t;
  long long a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, p = 0, g = 0, h = 0,
            i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, r = 0, u = 0,
            w = 0, x = 0, y = 0, z = 0;
  long long aa[10000];
  long long flag = 0, flag1 = 0, co = 0, co1 = 0, co2 = 0, co3 = 0, x1 = 0,
            x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0;
  long long ma = 0, mi = 10000000000;
  long long mid = 0, temp = 0, stop = 0, start = 0, ans = 0;
  double pi = 3.141592653589793;
  double d1 = 0.0, d2, d3, d4;
  vector<long long> v, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
  vector<string> vs, vs1, vs2, vs3, vs4;
  vector<pair<long long, long long> > vp, vp1, vp2;
  char ch, ch1, ch2[101][101];
  string str, str1, str2, str3, str4, str5;
  pair<long long, long long> pa;
  list<long long> li, li1;
  map<long long, long long> mp, mp1;
  set<long long> st;
  map<long long, long long>::iterator im;
  vector<long long>::iterator ivl, low, up;
  set<long long>::iterator it;
  vector<pair<long long, long long> >::iterator ivp;
  cin >> n;
  for (i = 1; i <= n / 2; i++) {
    co += i;
    v.push_back(i);
    if (co >= n) break;
  }
  if (co == n) {
    cout << v.size() << endl;
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
  } else {
    cout << v.size() - 1 << endl;
    x = v[v.size() - 2];
    y = v[v.size() - 1];
    for (i = 0; i < v.size() - 1; i++) {
      co1 += i;
      if (i != v.size() - 2) cout << v[i] << " ";
    }
    ans = x + y - (co - n);
    cout << ans << endl;
  }
  q++;
  ;
  return 0;
}

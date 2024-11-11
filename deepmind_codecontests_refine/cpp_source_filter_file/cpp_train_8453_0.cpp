#include <bits/stdc++.h>
using namespace std;
const long long PI = acosl(-1.0);
long long mod = 998244353;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const long long MAXN = 1e7 + 1;
long long spf[MAXN];
vector<int> prime;
void sieve() {
  spf[1] = 1;
  for (long long i = 2; i < MAXN; i++) spf[i] = i;
  for (long long i = 4; i < MAXN; i += 2) spf[i] = 2;
  for (long long i = 3; i * i < MAXN; i++) {
    if (spf[i] == i) {
      prime.push_back(i);
      for (long long j = i * i; j < MAXN; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
long long fact[100001], infac[100001];
long long fe(long long a, long long b) {
  long long temp = a;
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= temp;
      ans %= mod;
    }
    b /= 2;
    temp = temp * temp;
    temp %= mod;
  }
  return ans;
}
long long mi(long long a) { return (fe(a, mod - 2)); }
void fac() {
  fact[0] = 1;
  infac[0] = 1;
  for (long long i = 1; i < 101; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
    infac[i] = mi(fact[i]);
    infac[i] %= mod;
  }
}
long long ncr(long long a, long long b) {
  long long ans = fact[a];
  ans *= infac[b];
  ans %= mod;
  ans *= infac[a - b];
  ans %= mod;
  return ans;
}
int is_prime(int i) {
  int t = sqrt(i);
  for (long long j = 2; j < t + 1; j++)
    if (i % j == 0) return 0;
  return 1;
}
vector<int> prim;
void pri() {
  for (long long i = 2; i < 1001; i++) {
    if (is_prime(i)) prim.push_back(i);
  }
}
void solve() {
  int r, c;
  cin >> r >> c;
  vector<string> gr;
  string s;
  int a = 0, p = 0;
  for (long long i = 0; i < r; i++) {
    cin >> s;
    gr.push_back(s);
    for (long long j = 0; j < c; j++) {
      if (s[j] == 'A')
        a++;
      else
        p += 1;
    }
  }
  if (a == 0) {
    cout << "MORTAL"
         << "\n";
    return;
  } else if (p == 0) {
    cout << 0 << "\n";
    return;
  }
  int tt = 0;
  for (long long i = 0; i < c; i++) {
    if (gr[0][i] == 'P')
      break;
    else
      tt++;
  }
  if (tt == c) {
    cout << 1 << "\n";
    return;
  }
  tt = 0;
  for (long long i = 0; i < c; i++) {
    if (gr[r - 1][i] == 'P')
      break;
    else
      tt++;
  }
  if (tt == c) {
    cout << 1 << "\n";
    return;
  }
  tt = 0;
  for (long long i = 0; i < r; i++) {
    if (gr[i][0] == 'P')
      break;
    else
      tt++;
  }
  if (tt == r) {
    cout << 1 << "\n";
    return;
  }
  tt = 0;
  for (long long i = 0; i < r; i++) {
    if (gr[i][c - 1] == 'P')
      break;
    else
      tt++;
  }
  if (tt == r) {
    cout << 1 << "\n";
    return;
  }
  if (gr[0][0] == 'A') {
    cout << 2 << "\n";
    return;
  }
  if (gr[0][c - 1] == 'A') {
    cout << 2 << "\n";
    return;
  }
  if (gr[r - 1][0] == 'A') {
    cout << 2 << "\n";
    return;
  }
  if (gr[r - 1][c - 1] == 'A') {
    cout << 2 << "\n";
    return;
  }
  for (long long i = 1; i < r - 1; i++) {
    tt = 0;
    for (long long j = 0; j < c; j++) {
      if (gr[i][j] == 'P')
        break;
      else
        tt++;
    }
    if (tt == c) {
      cout << 2 << "\n";
      return;
    }
  }
  for (long long i = 1; i < c - 1; i++) {
    tt = 0;
    for (long long j = 0; j < r; j++) {
      if (gr[j][i] == 'P')
        break;
      else
        tt++;
    }
    if (tt == c) {
      cout << 2 << "\n";
      return;
    }
  }
  for (long long i = 0; i < c; i++)
    if (gr[0][i] == 'A') {
      cout << 3 << "\n";
      return;
    }
  for (long long i = 0; i < c; i++)
    if (gr[r - 1][i] == 'A') {
      cout << 3 << "\n";
      return;
    }
  for (long long i = 0; i < r; i++)
    if (gr[i][0] == 'A') {
      cout << 3 << "\n";
      return;
    }
  for (long long i = 0; i < r; i++)
    if (gr[i][c - 1] == 'A') {
      cout << 3 << "\n";
      return;
    }
  cout << 4 << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}

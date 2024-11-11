#include <bits/stdc++.h>
using namespace std;
vector<long long> prime;
void simpleSieve(int limit) {
  vector<bool> mark(limit + 1, true);
  prime.push_back(1);
  for (int p = 2; p * p < limit; p++) {
    if (mark[p] == true) {
      for (int i = p * p; i < limit; i += p) mark[i] = false;
    }
  }
  for (int p = 2; p < limit; p++) {
    if (mark[p] == true) {
      prime.push_back(p);
    }
  }
}
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
long long m = 1e9 + 7;
long long MX = 1e5 + 5;
void solve(long long t) {
  long long N;
  cin >> N;
  string a, b;
  cin >> a >> b;
  bool ck = 0;
  for (long long i = 0; i < N; i++) {
    if (a[i] > b[i]) {
      cout << -1 << endl;
      return;
    }
  }
  long long ans = 0;
  for (char c = 'a'; c <= 't'; c++) {
    vector<long long> temp;
    char rep = 'z';
    for (long long i = 0; i < N; i++) {
      if (a[i] != b[i] and a[i] == c) {
        temp.push_back(i);
        rep = min(rep, a[i]);
      }
    }
    if (temp.size() == 0) continue;
    ans++;
    for (long long i = 0; i < temp.size(); i++) {
      a[temp[i]] = rep;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve(i);
  }
  return (0);
}

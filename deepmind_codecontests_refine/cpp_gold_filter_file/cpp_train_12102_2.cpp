#include <bits/stdc++.h>
using namespace std;
bool comp(long long a, long long b) {
  if (a > b)
    return true;
  else
    return false;
}
int isP(long long n) {
  if (n == 1) return 0;
  if (n == 2 || n == 3) return 1;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long t = power(a, b / 2);
  if (b % 2 == 1)
    return t * t * a;
  else
    return t * t;
}
long long powMOD(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long t = powMOD(x, y / 2);
  if (y % 2 == 1)
    return t * t % 998244353 * x % 998244353;
  else
    return t * t % 998244353;
}
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first > p2.first) return true;
  if (p1.first == p2.first && p1.second > p2.second) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ar[n + 1];
    for (long long i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    long long foo = 0;
    map<long long, bool> hai;
    for (long long i = 1; i <= n; i++) {
      if (!hai[ar[i]]) {
        hai[ar[i]] = 1;
        foo++;
      }
    }
    if (foo > k)
      cout << -1 << "\n";
    else {
      vector<long long> ans;
      map<long long, bool> done;
      for (long long i = 1; i <= n; i++) {
        if (!done[ar[i]]) {
          done[ar[i]] = 1;
          ans.push_back(ar[i]);
        }
      }
      while (ans.size() < k) ans.push_back(1);
      cout << (ans.size() * n) << "\n";
      for (long long i = 1; i <= n; i++) {
        for (long long i = 0; i < ans.size(); i++) cout << ans[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}

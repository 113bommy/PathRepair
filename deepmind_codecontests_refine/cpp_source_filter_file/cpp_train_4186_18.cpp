#include <bits/stdc++.h>
using namespace std;
inline long long add(long long a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
inline long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
  return a;
}
inline long long mul(long long a, long long b) {
  return (long long)((long long)a * b % 1000000007);
}
long long min(long long a, long long b) { return a > b ? b : a; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long n, m, t, ar[1000000];
bool sv[1000000];
long long arr[1000000];
set<long long> st[1000000];
void solve() {
  int n;
  cin >> n;
  string Nik;
  cin >> Nik;
  vector<long long> stairs;
  for (int i = 0; i < n; i += 1) {
    if (Nik[i] == '1') stairs.push_back(i);
  }
  if (stairs.size() == 0)
    cout << n << '\n';
  else {
    int k = min(n - stairs[stairs.size() - 1], stairs[0]);
    int ans = max(n, 2 * (n - k));
    cout << ans << '\n';
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> &a, pair<long long, long long> &b) {
  return (a.second > b.second);
}
void show_vec(vector<pair<long long, long long> > v) {
  for (int i = 0; i < v.size(); i++)
    cout << v[i].first << " " << v[i].second << "\n";
  ;
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
long long fact(long long n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}
bool check_prime(int n) {
  if (n <= 1) return false;
  if (n < 4) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void solve() {
  long long n, i, j, k = 0, m;
  string s, t = "", t1 = "";
  cin >> n >> s;
  i = n, j = 0;
  m = n;
  if (m % 2) m--;
  i = m / 2;
  while (i > 0) {
    t = s.substr(0, i);
    t1 = s.substr(i, i);
    if (t == t1) k = max(k, (long long)t.length());
    i--;
  }
  if (k == 0) k++;
  cout << n - k + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

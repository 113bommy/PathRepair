#include <bits/stdc++.h>
using namespace std;
const int fx[] = {+1, -1, +0, +0};
const int fy[] = {+0, +0, +1, -1};
int Set(int &N, int pos) { return N = N | (1 << pos); }
int reset(int &N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
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
bool isPrime(long long n) {
  if (n <= 1) return false;
  long long sqrtn = sqrt(n);
  for (long long i = 2; i <= sqrtn; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  int mx = -1;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    mx = max(mx, x);
  }
  if (mx <= 25)
    cout << 0 << "\n";
  else
    cout << 25 - mx << "\n";
}
int main() {
  init();
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

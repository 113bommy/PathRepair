#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int n, m, d, cnt = 1, x;
map<int, int> ma;
std::vector<int> a, b;
priority_queue<int, std::vector<int>, greater<int>> q;
int main() {
  cin >> n >> m >> d;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
    b.push_back(x);
  }
  sort(a.begin(), a.end());
  ma[a[0]] = 1;
  q.push(0);
  for (int i = 1; i < n; i++) {
    int ii = q.top();
    if (a[i] - a[ii] > d) {
      ma[a[i]] = ma[a[ii]];
      q.pop();
    } else {
      cnt++;
      ma[a[i]] = cnt;
    }
    q.push(i);
  }
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    printf("%d ", ma[b[i]]);
  }
  printf("\n");
  return 0;
}

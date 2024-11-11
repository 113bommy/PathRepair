#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
const double EPS = (1e-7);
const long long mod = (1e9 + 7), OO = 1e9;
long long Ceil(long long x, long long y) { return (x + y - 1) / y; }
void run() {}
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long n, m, k, d;
vector<long long> v(32);
int main() {
  fast();
  run();
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> d;
    long long k = (long long)ceil(log(d));
    v[k]++;
  }
  while (m--) {
    cin >> d;
    long long cnt = 0;
    for (long long i = 31; i >= 0 && d; i--) {
      long long b = min(v[i], d >> i);
      cnt += b;
      d -= (1 << i) * b;
    }
    cout << ((d > 0) ? -1ll : cnt) << '\n';
    ;
  }
}

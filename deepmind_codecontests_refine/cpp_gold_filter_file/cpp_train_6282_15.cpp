#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159265358979323846;
long long mod = 1000000000 + 7;
const int N = 1e5 + 5;
vector<bool> prime(N, true);
bool Rev(long long a, long long b) { return (a > b); }
void solve() {
  long long p, q, i;
  cin >> p >> q;
  vector<long long> a(p + 1, 0);
  vector<long long> b(q + 1, 0);
  for (long long i = 0; i < p + 1; i += 1) cin >> a[i];
  for (long long i = 0; i < q + 1; i += 1) cin >> b[i];
  if (p > q) {
    if (a[0] * b[0] > 0)
      cout << "Infinity";
    else
      cout << "-Infinity";
    return;
  } else if (p < q) {
    cout << "0/1";
  } else {
    long long x = a[0];
    long long y = b[0];
    long long mn = min(abs(x), abs(y));
    for (long long i = 2; i < mn + 1; i += 1) {
      if (x % i == 0 and y % i == 0) {
        x /= i;
        y /= i;
        i--;
      }
    }
    if (x * y < 0) {
      cout << "-" << abs(x) << "/" << abs(y);
    } else
      cout << abs(x) << "/" << abs(y);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  solve();
}

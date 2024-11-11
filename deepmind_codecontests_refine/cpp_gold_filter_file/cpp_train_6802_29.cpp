#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int add(int x, int y, int CMOD = MOD) { return (0LL + x + y) % CMOD; }
int mult(int x, int y, int CMOD = MOD) { return (1LL * x * y) % CMOD; }
long long fast_expo(long long x, long long y, long long CMOD = MOD) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long ans = fast_expo(x, y / 2, CMOD);
  ans = mult(ans, ans, CMOD);
  if (y & 1) ans = mult(ans, x, CMOD);
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long gen(long long x, long long y) {
  if (x == y) return x;
  return x + rng() % (y - x + 1);
}
const int TAM = 1e5 + 100;
const long long INF = LLONG_MAX / 4;
vector<pair<int, pair<int, int> > > v(3);
bool mycomp(pair<int, pair<int, int> > x, pair<int, pair<int, int> > y) {
  return x.second.first < y.second.first;
}
int main() {
  int S;
  cin >> S;
  int a, b, c;
  cin >> a >> b >> c;
  int total = a + b + c;
  cout << fixed << setprecision(10);
  if (total == 0)
    cout << S << " 0 0" << endl;
  else
    cout << 1.0l * a * S / total << " " << 1.0l * b * S / total << " "
         << 1.0l * c * S / total << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const long long inf = 1e18;
const int maxm = 1005;
vector<vector<char>> matrix(maxm, vector<char>(maxm));
struct event {
  int x, y, size;
};
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
class even {
 public:
  int a, b, c;
};
class evenl {
 public:
  int a, b, c, ind;
};
struct myComp {
  constexpr bool operator()(evenl f, evenl s) const noexcept {
    int z = f.b - f.a;
    int z2 = s.b - s.a;
    z -= f.c;
    z2 -= s.c;
    return z < z2;
  }
};
long long poww(long long a, long long b, long long m) {
  if (b == 0) return 1ll;
  if (b % 2 == 1) return a * poww(a, b - 1, m) % m;
  long long rs = poww(a, b / 2, m);
  rs = rs * rs % m;
  return rs;
}
long long fact[N];
long long ncr(long long n, long long r) {
  long long num = fact[n];
  long long deno = fact[n - r] * fact[r] % mod;
  deno = poww(deno, mod - 2, mod);
  num = num * deno;
  num = num % mod;
  return num;
}
int spf[N + 1];
void sieve() {
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0)
      spf[i] = 2;
    else
      spf[i] = i;
  }
  for (int i = 3; i * i <= N; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < N; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
void solve() {
  long long n, x1, x2;
  cin >> n >> x1 >> x2;
  vector<pair<long long, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
  sort(a.begin(), a.end());
  for (int i = 0; i < n - 1; i++) {
    int z = (x1 + a[i].first - 1) / a[i].first;
    if (z + i < n) {
      int y = (x2 + a[z + i].first - 1) / a[z + i].first;
      if (z + y + i <= n) {
        cout << "Yes"
             << "\n";
        ;
        cout << z << " " << y << "\n";
        for (int k = i; k < i + z; k++) cout << a[k].second + 1 << " ";
        cout << "\n";
        for (int k = i + z; k < i + z + y; k++) cout << a[k].second + 1 << " ";
        cout << "\n";
        return;
      }
    }
    z = (x2 + a[i].first - 1) / a[i].first;
    if (z + i < n) {
      int y = (x1 + a[z + i].first - 1) / a[z + i].first;
      if (z + y + i <= n) {
        cout << "Yes"
             << "\n";
        ;
        cout << y << " " << z << "\n";
        for (int k = z + i; k < z + i + y; k++) cout << a[k].second + 1 << " ";
        cout << "\n";
        for (int k = i; k < i + z; k++) cout << a[k].second + 1 << " ";
        cout << "\n";
        return;
      }
    }
  }
  cout << "No";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}

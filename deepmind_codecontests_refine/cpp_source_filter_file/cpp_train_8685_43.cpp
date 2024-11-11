#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dy[] = {-1, 1, 0, 0, 1, -1, -1, 1};
void run();
int main() {
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(16);
  run();
}
int A[100][100];
int n, m;
bool is_square(long long x) {
  long long rt = sqrt(x);
  for (long long y = rt; y <= rt + 3; ++y)
    if (y * y == x) return 1;
  for (long long y = rt - 3; y < rt; ++y)
    if (y * y == x) return 1;
  return 0;
}
map<long long, set<long long> > possibilities(long long n) {
  map<long long, set<long long> > res;
  for (long long k = 1; k <= 100; ++k) {
    long long nk = k * k * n;
    for (long long c = 1; c * c <= nk; ++c) {
      if (nk % c == 0) {
        long long d = nk / c;
        if (d <= c) break;
        res[k].insert(d - c);
      }
    }
  }
  return res;
}
long long T = 100000000;
void run() {
  long long n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << 1 << "\n";
    return;
  }
  if (n == 1) {
    map<long long, set<long long> > A = possibilities(m - 1);
    assert(!A.empty());
    long long k = 2 * (A.begin()->first);
    for (int j = 0; j < m - 1; ++j) {
      cout << k << " ";
    }
    cout << *(A.begin()->second).begin() << "\n";
    return;
  }
  if (m == 1) {
    map<long long, set<long long> > A = possibilities(n - 1);
    assert(!A.empty());
    long long k = 2 * (A.begin()->first);
    for (int j = 0; j < n - 1; ++j) {
      cout << k << "\n";
    }
    cout << *(A.begin()->second).begin() << "\n";
    return;
  }
  map<long long, set<long long> > A = possibilities(n - 1),
                                  B = possibilities(m - 1);
  for (auto it : A) {
    long long k = 2 * it.first;
    for (long long b : B[it.first]) {
      if (b > T) continue;
      for (long long a : it.second) {
        if (a > T) continue;
        assert(is_square(a * a + (n - 1) * k * k));
        assert(is_square(b * b + (m - 1) * k * k));
        long long aa = (n - 1) * a * a;
        long long bb = (m - 1) * b * b;
        for (long long x = 1; x <= 30000; ++x) {
          long long xx = x * x;
          if (is_square(aa + xx) && is_square(bb + xx)) {
            for (int i = 0; i < n - 1; ++i) {
              for (int j = 0; j < m - 1; ++j) cout << k << " ";
              cout << b << "\n";
            }
            for (int j = 0; j < m - 1; ++j) cout << a << " ";
            cout << x << "\n";
            return;
          }
        }
      }
    }
  }
  assert(0);
}

#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000")
using namespace std;
void solve(bool);
void precalc();
clock_t start;
int testNumber = 1;
bool todo = true;
bool stress = false;
int main() {
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  precalc();
  cout.precision(10);
  cout << fixed;
  int testNum = 1;
  while (t--) {
    solve(true);
    ++testNumber;
  }
  return 0;
}
template <typename T>
T binpow(T q, T w, T mod) {
  if (!w) return 1 % mod;
  if (w & 1) return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}
void precalc() {}
template <typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template <typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}
void solve(bool read) {
  int m, n;
  cin >> m >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = n - 1; i >= 0; --i) {
    a[i] -= a[0];
  }
  int L = -1, R = 1e9 + 2;
  while (L + 1 < R) {
    int k = (L + R) / 2;
    bool good = false;
    for (int w = 0; w < 2; ++w) {
      for (int start = 1; start <= 2 && start <= n; ++start) {
        if (start == 2 && a[1] - a[0] > 2 * k + 1) {
          continue;
        }
        bool f = true;
        int border = k;
        if (start == 2) {
          border = max(border, a[1]);
        }
        for (int i = start; i < n; ++i) {
          if (a[i] <= border + 1) {
            border = a[i] + k;
          } else {
            if (a[i] - border > k + 1) {
              f = false;
              break;
            } else {
              int j = i;
              int next_border = border;
              while (j < n && a[j] - border <= k + 1 &&
                     (j == i || a[j] > a[j - 1] + 1)) {
                if (j > i) {
                  next_border = max(next_border, a[j - 1] + k);
                }
                ++j;
              }
              if (next_border + 1 >= a[j - 1]) {
                border = a[j - 1] + k;
              } else {
                border = a[j - 1];
                if (j > i + 1) {
                  border = max(border, a[j - 2] + k);
                }
              }
              i = j - 1;
            }
          }
        }
        if (f) {
          if (start == 1 && border >= m - 1) {
            good = true;
            break;
          }
          if (start == 2 && (border + k >= m + a[1] - 1 || border >= m - 1)) {
            good = true;
            break;
          }
        }
      }
      for (int i = 1; i < n; ++i) {
        a[i] = m - a[i];
      }
      sort(a.begin(), a.end());
    }
    if (good) {
      R = k;
    } else {
      L = k;
    }
  }
  cout << R << "\n";
}

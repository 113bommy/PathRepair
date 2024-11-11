#include <bits/stdc++.h>
template <typename T>
T gcd(T a, T b) {
  return ((a % b == 0) ? b : gcd(b, a % b));
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
using LL = long long;
constexpr LL LINF = 334ll << 53;
constexpr int INF = 15 << 26;
constexpr LL MOD = 1E9 + 7;
namespace Problem {
using namespace std;
class Solver2 {
 public:
  int n, k;
  Solver2(LL n, LL k) : n(n), k(k){};
  void solve() {
    if (k == 2) {
      if (n > 2) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        vector<pair<int, int>> p = {{1, 2}, {2, 1}};
        for (int i = 0; i < n; ++i) {
          cout << p[i].first << ' ' << p[i].second << "\n";
        }
      }
    } else if (k == 3) {
      if (n > 6) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        vector<pair<int, int>> p = {{1, 3}, {3, 1}, {1, 2},
                                    {2, 3}, {3, 2}, {2, 1}};
        for (int i = 0; i < n; ++i) {
          cout << p[i].first << ' ' << p[i].second << "\n";
        }
      }
    } else {
      if (n > (LL)k * (k - 1)) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        vector<pair<int, int>> p;
        p.emplace_back(1, k);
        p.emplace_back(k, 1);
        for (int i = k - 2; k >= 1 && p.size() < n; --i) {
          for (int j = 1; j + i <= k; ++j) {
            p.emplace_back(j, i + j);
          }
        }
        for (int i = 1; i <= k - 2 && p.size() < n; ++i) {
          for (int j = 1; j + i <= k; ++j) {
            p.emplace_back(i + j, j);
          }
        }
        for (int i = 0; i < n; ++i) {
          cout << p[i].first << ' ' << p[i].second << "\n";
        }
      }
    }
  }
};
}  // namespace Problem
int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  long long n = 0, k;
  std::cin >> n >> k;
  Problem::Solver2 sol(n, k);
  sol.solve();
  return 0;
}

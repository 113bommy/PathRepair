#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
const int N = 300005, M = N;
int power(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 1) return (power(a, b - 1) * a) % 998244353;
  int q = power(a, b / 2);
  return (q * q) % 998244353;
}
int main() {
  long long mini = 1e9;
  long long n, m, i, j, a, b;
  cin >> n >> m >> i >> j >> a >> b;
  vector<pair<int, int> > v;
  v.push_back({1, 1});
  v.push_back({n, 1});
  v.push_back({1, m});
  v.push_back({n, m});
  for (auto u : v) {
    if (u.first == i && u.second == j) {
      cout << 0;
      return 0;
    }
  }
  if ((i - a < 1 && i + a > n) || (j - b < 1 && j + b > n)) {
    cout << "Poor Inna and pony!";
    return 0;
  }
  for (auto u : v) {
    if (abs(u.second - j) > 0 && abs(u.first - i) % a == 0) {
      if ((abs(u.first - i) / a) % 2 == (abs(u.second - j) / b) % 2) {
        mini = min(mini, max((abs(u.first - i) / a), (abs(u.second - j) / b)));
      }
    }
  }
  if (mini == 1e9) {
    cout << "Poor Inna and pony!";
  } else {
    cout << mini;
  }
}

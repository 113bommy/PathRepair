#include <bits/stdc++.h>
using namespace std;
int ri() {
  int x;
  if (scanf(" %d", &x) == EOF) return -1;
  return x;
}
long long int rl() {
  long long int x;
  if (cin >> x) return x;
  return -1;
}
string rs() {
  string s;
  if (cin >> s) return s;
  return "";
}
const long long int mod = 998244353;
struct SingleCase {
  int n;
  vector<int> v, halfIdx;
  vector<long long int> memo, Fact, Inv;
  long long int fact(int a) {
    if (a == 0) return 1;
    long long int& ret = Fact[a];
    if (ret != -1) return ret;
    return ret = a * fact(a - 1) % mod;
  }
  long long int power(int a, long long int x) {
    if (x == 0) return 1;
    if (x == 1) return a;
    if (x % 2) return power(a, x - 1) * a % mod;
    long long int y = power(a, x / 2);
    return y * y % mod;
  }
  long long int inverse(int a) {
    long long int& ret = Inv[a];
    if (ret != -1) return ret;
    return ret = power(a, mod - 2);
  }
  long long int doit(int idx) {
    long long int& ret = memo[idx];
    if (ret != -1) return ret;
    ret = 0;
    ret = 1;
    int r = halfIdx[idx];
    for (int i = r; i >= 0; --i) {
      long long int cur = inverse(n - 2 - halfIdx[i]) * doit(i) % mod;
      ret = (ret + cur) % mod;
    }
    return ret;
  }
  void computeHalfIdx() {
    halfIdx = vector<int>(n, -1);
    int x = -1, y = 0;
    while (y < n) {
      if (x + 1 < n && 2 * v[x + 1] <= v[y])
        x++;
      else {
        halfIdx[y] = x;
        y++;
      }
    }
  }
  bool solveCase() {
    n = ri();
    if (n < 0) return false;
    for (int i = 0; i < n; ++i) v.push_back(ri());
    sort(v.begin(), v.end());
    memo = vector<long long int>(n, -1);
    Fact = vector<long long int>(n, -1);
    Inv = vector<long long int>(n, -1);
    computeHalfIdx();
    long long int ret;
    if (n > 2 && 2 * v[n - 2] > v[n - 1])
      ret = 0;
    else
      ret = doit(n - 1) * fact(n - 1) % mod;
    cout << ret << endl;
    return true;
  }
};
int main() {
  while (SingleCase().solveCase()) {
  };
  return 0;
}

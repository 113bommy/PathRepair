#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) { return n | (1LL << i); }
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int main() {
  int n, a, b, c, d, start, len;
  scanf("%d%d%d%d%d%d%d", &n, &a, &b, &c, &d, &start, &len);
  vector<int> t(n), q(n);
  for (int i = 0; i < n; i++) scanf("%d%d", &t[i], &q[i]);
  int j = 0;
  long long df = 0, mn = 0, ac = start;
  vector<int> T;
  T.push_back(-1);
  for (int i = 0; i < n; i++) T.push_back(t[i]);
  for (int i = 0; i < n; i++) {
    while (j < n && t[j] - t[i] < len) {
      df += (q[j] ? c : -d);
      mn = min(mn, df);
      j++;
    }
    if (ac + mn >= 0) {
      cout << T[i] + 1 << '\n';
      return 0;
    }
    df -= (q[i] ? c : -d);
    mn -= (q[i] ? c : -d);
    ac += (q[i] ? a : -b);
    if (ac < 0) {
      puts("-1");
      return 0;
    }
  }
  cout << T[n] << '\n';
}

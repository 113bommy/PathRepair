#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const long long INF = 1LL * inf * inf;
const double eps = 1e-9;
const int MAXN = 2500;
const int md = (int)1e9 + 7;
const double EPS = 1e-5;
const long long maxll = numeric_limits<long long>::max();
template <typename name>
inline name sqr(name x) {
  return x * x;
}
template <typename name>
inline name bpow(name base, long long exp, long long md = maxll) {
  if (exp == 0) return 1;
  if (exp % 2 == 1)
    return (base * bpow(base, exp - 1, md)) % md;
  else {
    name k = bpow(base, exp / 2, md);
    return (k * k) % md;
  }
}
int n, m, ans1, ans2, use[11];
long long step[40], res;
vector<int> roz;
void check(int x) {
  int flag = 0;
  for (int i = 0; i < 10; i++) use[i] = 0;
  int it = 0;
  int x1 = x;
  if (x == 0) use[0] = 1, it++;
  while (x) {
    use[x % 7] += 1;
    x /= 7;
    it++;
  }
  if (it < ans1) {
    it++;
    use[0]++;
  }
  if (it < ans1) use[0]++;
  if (flag) return;
  for (int i = 0; i < m; i++) {
    int q = i, iter = 0, flag = 0;
    if (q == 0) use[0]++, iter++;
    while (q) {
      use[q % 7]++;
      q /= 7;
      iter++;
    }
    if (iter < ans2) {
      use[0]++;
      iter++;
    }
    if (iter < ans2) use[0]++;
    for (int j = 0; j < 10; j++)
      if (use[j] > 1) flag = 1;
    if (!flag) res++;
    q = i;
    iter = 0;
    if (q == 0) use[0]--, iter++;
    while (q) {
      use[q % 7]--;
      q /= 7;
      iter++;
    }
    if (iter < ans2) {
      use[0]--;
      iter++;
    }
    if (iter < ans2) use[0]--;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  if (n > m) swap(n, m);
  ans1 = 1;
  ans2 = 1;
  step[0] = 1;
  for (int i = 1; i < 12; i++) {
    step[i] = step[i - 1] * 7;
    if (m > step[i]) ans2++;
    if (n > step[i]) ans1++;
  }
  if (ans1 + ans2 > 7) return cout << 0, 0;
  for (int i = 0; i < n; i++) {
    check(i);
  }
  cout << res;
  return 0;
}

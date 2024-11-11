#include <bits/stdc++.h>
using namespace std;
bool check(long long x) {
  if (x == 0) return false;
  while (x) {
    if ((x % 10 != 4) && (x % 10 != 7)) return false;
    x /= 10;
  }
  return true;
}
const int max_f = 20;
const int max_num = (int)1e9;
int p[max_f], fact[max_f];
bool used[max_f];
int main() {
  int n, k, f;
  scanf("%d%d", &n, &k);
  vector<long long> v;
  v.push_back(4), v.push_back(7);
  for (int i = 0; i < ((int)(v).size()); ++i) {
    if (v[i] * 10 + 4 <= max_num) v.push_back(v[i] * 10 + 4);
    if (v[i] * 10 + 7 <= max_num) v.push_back(v[i] * 10 + 7);
  }
  fact[0] = 1;
  for (f = 1; fact[f - 1] * f <= k; ++f) fact[f] = fact[f - 1] * f;
  if (f > n) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < f; ++i)
    for (p[i] = 0; p[i] < f; ++p[i])
      if (!used[p[i]]) {
        if (k <= fact[f - i - 1]) {
          used[p[i]] = true;
          break;
        }
        k -= fact[f - i - 1];
      }
  int res = 0;
  for (int i = 0; i < ((int)(v).size()); ++i)
    if ((v[i] <= n - f) ||
        ((v[i] <= n) && check(p[v[i] - (n - f + 1)] + (n - f + 1))))
      res++;
  printf("%d\n", res);
  return 0;
}

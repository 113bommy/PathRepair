#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int mx = 1e5 + 10;
long long int binpow(long long int base, long long int exp) {
  long long int res = 1;
  while (1) {
    if (exp & 1) res *= base;
    exp >>= 1;
    if (!exp) break;
    base *= base;
  }
  return res;
}
int main(int argc, char const *argv[]) {
  int n, m;
  scanf("%d %d", &m, &n);
  std::vector<int> v(n, 1);
  for (int i = 0; i < n; ++i) {
    printf("%d\n", m + 1);
    fflush(stdout);
    int s;
    cin >> s;
    if (s == 0 || s == -2) return 0;
    if (s == 1) v[i] = 0;
  }
  int l = 0, r = m, i = 0;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    printf("%d\n", mid);
    fflush(stdout);
    int s;
    cin >> s;
    if (s == 0 || s == -2) {
      return 0;
    }
    if (v[i % n]) {
      if (s == -1)
        r = mid - 1;
      else
        l = mid + 1;
    } else {
      if (s == -1)
        l = mid + 1;
      else
        r = mid - 1;
    }
    i++;
  }
  printf("%d\n", l);
  fflush(stdout);
  int k;
  cin >> k;
  return 0;
  return 0;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
vector<unsigned long long> v1(maxn);
vector<unsigned long long> v2(maxn);
unsigned long long n, c;
const unsigned long long oo = 1000000000000000000ll;
int check(unsigned long long x) {
  unsigned long long sum = 0;
  for (int i = 1; i <= n; i++) {
    if (v1[i] > oo / x) return c + 1;
    unsigned long long day = 1 + v1[i] * x / v2[i];
    if (day > c || sum > c - day) return c + 1;
    sum += day;
  }
  if (sum > c) return c + 1;
  if (sum == c) return c;
  if (sum < c) return c - 1;
}
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) cin >> v1[i] >> v2[i];
  unsigned long long l = 1, r = 1e18;
  unsigned long long lm = 0, rm = 0;
  while (l <= r) {
    unsigned long long mid = (l + r) >> 1;
    unsigned long long x = check(mid);
    if (x < c) {
      l = mid + 1;
    } else if (x > c) {
      r = mid - 1;
    } else {
      l = mid + 1;
      rm = mid;
    }
  }
  l = 1, r = 1e18;
  while (l <= r) {
    unsigned long long mid = (l + r) >> 1;
    unsigned long long x = check(mid);
    if (x < c) {
      l = mid + 1;
    } else if (x > c) {
      r = mid - 1;
    } else {
      r = mid - 1;
      lm = mid;
    }
  }
  if (lm == 1 && rm == 1e18) {
    cout << -1 << endl;
  } else if (lm == 0 && rm == 0)
    cout << 0 << endl;
  else
    cout << rm - lm - 1 + (check(lm) == c) + (check(rm) == c) << endl;
  return 0;
}

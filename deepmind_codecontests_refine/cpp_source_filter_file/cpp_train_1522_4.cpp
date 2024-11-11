#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-8;
const int INF = 1000000000;
int a, b, k;
vector<int> p;
bool prime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
};
bool ok1(int n, int k) {
  if (n < k) return false;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
};
int f1(int n, int k) {
  int res = 0;
  for (int i = 1; i <= n / k; ++i)
    if (ok1(i, k)) ++res;
  return res;
};
int recit(int n, int tp) {
  if (n == 0) return 0;
  n /= p[tp];
  int res = n;
  for (int i = tp + 1; i < p.size() && n >= p[i]; ++i) res -= recit(n, i);
  return res;
};
int f2(int n, int k) {
  int res = n / k;
  if (p.empty())
    for (int i = (int)(0); i < (int)(k); ++i)
      if (prime(i)) p.push_back(i);
  for (int i = (int)(0); i < (int)(p.size()); ++i) res -= recit(n / k, i);
  return res;
};
int f(int n, int k) {
  if (k >= 10000)
    return f1(n, k);
  else
    return f2(n, k);
};
int main() {
  cin >> a >> b >> k;
  if (!prime(k)) {
    printf("0");
    return 0;
  };
  cout << f(b, k) - f(a - 1, k);
  return 0;
};

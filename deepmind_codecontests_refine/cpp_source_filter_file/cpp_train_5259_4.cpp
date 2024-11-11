#include <bits/stdc++.h>
using namespace std;
void rs(int &x) { scanf("%d", &x); }
void rsl(long long &x) { scanf("%I64d", &x); }
void rsd(double &x) { scanf("%lf", &x); }
void rss(char *str) { scanf("%s", str); }
void ws(int &x) { printf("%d ", x); }
void wsl(long long &x) { printf("%I64d ", x); }
void wsd(double &x) { printf("%lf ", x); }
void wss(char *str) { printf("%s ", str); }
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int const N = (1e5) + 5;
int const mod = (1e9) + 7;
int p[N];
int val[N];
int cl = 1;
int main() {
  int n;
  cin >> n;
  int maxs = 0;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    val[p[i]] = val[p[i] - 1];
    maxs = max(maxs, val[p[i]]);
  }
  cout << maxs;
  return 0;
}

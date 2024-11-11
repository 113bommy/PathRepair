#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")
const double EPS = 1E-9;
const int INF = 1000000000;
const long long INF64 = (long long)1E18;
const double PI = 3.1415926535897932384626433832795;
unsigned long long solve(vector<int> a, vector<int> b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  unsigned long long sa = 0, sb = 0;
  for (int i = 0; i < (int)(a.size()); i++) sa += a[i];
  for (int i = 0; i < (int)(b.size()); i++) sb += b[i];
  unsigned long long cnt = 0;
  unsigned long long res = INF64;
  for (int i = (int)(a.size()) - 1; i >= 0; i--) {
    cnt++;
    sa -= a[i];
    unsigned long long cur = cnt * (sa + sb);
    res = min(res, cur);
  }
  return res;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < (int)(n); i++) scanf("%d", &a[i]);
  for (int i = 0; i < (int)(m); i++) scanf("%d", &b[i]);
  unsigned long long res = min(solve(a, b), solve(b, a));
  cout << res << endl;
  return 0;
}

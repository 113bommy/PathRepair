#include <bits/stdc++.h>
using namespace std;
const long long LLINF = 1e18;
const int INF = 1e9;
const int MOD = 20101009;
const int HMOD = 999959;
const int VMOD = 5000000;
const int MAXN = 3e5 + 10;
const int MAXM = 5e5 + 10;
const int INV = 10050505;
const long long LLINV = 1e18;
const double eps = 1e-3;
int dirx[5] = {0, -1, 1, 0, 0}, diry[5] = {0, 0, 0, -1, 1};
int n;
int a[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  int cnt = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i] == a[i - 1])
      cnt++;
    else
      break;
  }
  if (cnt > n / 2)
    puts("Bob");
  else
    puts("Alice");
  return 0;
}

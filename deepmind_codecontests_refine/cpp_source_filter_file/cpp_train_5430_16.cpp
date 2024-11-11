#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const long double EPS = 1e-9;
const int MOD = 1000000007;
const long long LLINF = 1000000000000000001;
const int maxn = 100042;
int n, m;
int ans;
int a[maxn];
bool poss(int v) {
  int act = 0;
  for (int i = 1; i <= n; i++) {
    int best = a[i];
    if (best < act) {
      if (act - best > v)
        return false;
      else {
        best = act;
      }
    } else if ((act + m) - best <= v)
      best = act;
    act = best;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int b = 0;
  int e = m + 1;
  while (b <= e) {
    int m = (b + e) / 2;
    if (poss(m))
      e = m - 1;
    else
      b = m + 1;
  }
  cout << b << endl;
}

#include <bits/stdc++.h>
using namespace std;
long long int n, m;
long long int arr[300000];
long long int par[6000];
long long int dep[6000];
long long int cou[6000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int TESTS, q, a, s, b, r, l, k, c, p, h, w, d, x, y, z, xs, ys, t;
  TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    cin >> n >> d;
    long long int maxi = n * (n - 1) / 2;
    long long int mini = 0;
    x = n - 1;
    long long int cur = 2;
    w = 1;
    while (x > 0) {
      mini += w * min(x, cur);
      x -= cur;
      w++;
      cur *= 2;
    }
    if (d < mini || d > maxi) {
      cout << "NO\n";
      continue;
    }
    if (n == 2) {
      cout << "YES\n";
      cout << "1 2\n";
      continue;
    }
    par[0] = dep[0] = 0;
    for (long long int i = 1; i <= n - 1; i++) {
      par[i] = i - 1;
      dep[i] = dep[i - 1] + 1;
    }
    for (long long int i = 0; i <= n - 2; i++) cou[i] = 1;
    cou[n - 1] = 0;
    cur = maxi;
    long long int chil = n - 2;
    for (long long int i = 2; i <= n - 1; i++) {
      long long int alow = 1e15;
      long long int ind = -1;
      for (long long int j = 0; j <= n - 1; j++)
        if (alow > dep[j] && dep[j] < dep[par[i]] && cou[j] < 2 &&
            cur - (dep[par[i]] - dep[j]) * chil >= d) {
          alow = dep[j];
          ind = j;
        }
      if (ind != -1) {
        cur -= (dep[par[i]] - alow) * chil;
        cou[par[i]]--;
        cou[ind]++;
        par[i] = ind;
        dep[i] = dep[ind] + 1;
        for (long long int j = i + 1; j <= n - 1; j++) dep[i] = dep[i - 1] + 1;
      }
      chil--;
    }
    cout << "YES\n";
    for (long long int i = 0; i <= n - 1; i++) cout << par[i] + 1 << " ";
    cout << "\n";
  }
  return 0;
}

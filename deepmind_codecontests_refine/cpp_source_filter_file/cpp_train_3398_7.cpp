#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e6 + 3;
const long long maxval = 1e18;
long long v1[nmax], v2[nmax], p[23], k, st, dr, sol, m;
int n1, n2, n, nr;
vector<long long> t1;
vector<long long> t2;
int check(long long k) {
  int nr = 0, dr = 0;
  for (int i = 0; i < t1.size(); ++i) {
    while (dr < t2.size() && t2[dr] <= k / t1[i]) ++dr;
    nr += dr;
  }
  return nr;
}
void back1(long long usu, int k, long long bound) {
  if (k > n1) {
    t1.push_back(usu);
    return;
  }
  while (bound) {
    back1(usu, k + 1, bound);
    usu *= v1[k];
    bound /= v1[k];
  }
}
void back2(long long usu, int k, long long bound) {
  if (k > n2) {
    t2.push_back(usu);
    return;
  }
  while (bound) {
    back2(usu, k + 1, bound);
    usu *= v2[k];
    bound /= v2[k];
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  for (int i = 1; i <= n; ++i) {
    if (i % 2)
      v1[++n1] = p[i];
    else
      v2[++n2] = p[i];
  }
  back1(1, 1, maxval);
  back2(1, 1, maxval);
  cin >> k;
  sort(t1.rbegin(), t1.rend());
  sort(t2.begin(), t2.end());
  st = 1;
  dr = maxval;
  sol = maxval;
  while (st <= dr) {
    m = (st + dr) / 2;
    nr = check(m);
    if (nr < k)
      st = m + 1;
    else if (nr >= k) {
      dr = m - 1;
      sol = m;
    }
  }
  if (sol != maxval)
    cout << sol;
  else
    cout << -1;
  return 0;
}

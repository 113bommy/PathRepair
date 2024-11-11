#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int n;
bool A[MAXN];
string s;
void load() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) A[i] = (s[i] == 'U');
}
int U, D;
int sU[MAXN], sD[MAXN];
int sUk[MAXN], sDk[MAXN];
void compute() {
  int indU = 1, indD = 1;
  for (int i = 0; i < n; i++) {
    if (A[i]) {
      sUk[indU] = sUk[indU - 1] + i;
      sD[i] = sD[i - 1];
      sU[i] = sU[i - 1] + 1;
      indU++;
    } else {
      sDk[indD] = sDk[indD - 1] + i;
      sU[i] = sU[i - 1];
      sD[i] = sD[i - 1] + 1;
      indD++;
    }
  }
  U = indU + 1;
  D = indD + 1;
}
long long sols[MAXN];
void solve() {
  compute();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') {
      long long sol = 0;
      int r = sD[n - 1] - sD[i];
      int l = (i ? sU[i - 1] : 0);
      int k = min(r, l);
      if (k) sol += 2 * (sDk[sD[i] + k] - sDk[sD[i]]);
      if (k) sol -= 2 * (sUk[sU[i - 1]] - sUk[sU[i - 1] - k]);
      if (r <= l)
        sol += n - i;
      else
        sol += i + 1 + 2 * (sDk[sD[i] + k + 1] - sDk[sD[i] + k] - i);
      sols[i] = sol;
    }
  }
  for (int i = 0; i < n; i++) {
    A[n - i - 1] = (s[i] == 'D');
  }
  compute();
  for (int j = 0; j < n; j++) {
    if (s[j] == 'D') {
      int i = n - j - 1;
      long long sol = 0;
      int r = sD[n - 1] - sD[i];
      int l = (i ? sU[i - 1] : 0);
      int k = min(r, l);
      if (k) sol += 2 * (sDk[sD[i] + k] - sDk[sD[i]]);
      if (k) sol -= 2 * (sUk[sU[i - 1]] - sUk[sU[i - 1] - k]);
      if (r <= l)
        sol += n - i;
      else
        sol += i + 1 + 2 * (sDk[sD[i] + k + 1] - sDk[sD[i] + k] - i);
      sols[j] = sol;
    }
  }
  for (int i = 0; i < n; i++) printf("%lld ", sols[i]);
  printf("\n");
}
int main() {
  load();
  solve();
  return 0;
}

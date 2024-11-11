#include <bits/stdc++.h>
using namespace std;
const int maxn = 100020;
const int MOd = 1e9 + 7;
int a;
int ar[maxn];
int dn[maxn][2];
int dn2[2][2];
vector<int> w[maxn];
inline int add(int a, int b) { return a + b >= MOd ? a + b - MOd : a + b; }
inline int mul(int a, int b) { return (long long)a * b % MOd; }
int f(int n, int s) {
  if (!w[n].size()) {
    dn[n][1] = 1;
    dn[n][0] = 0;
  }
  if (dn[n][s] != -1) return dn[n][s];
  dn[n][1] = 1;
  dn[n][0] = 0;
  for (int i = 0; i < w[n].size(); i++) {
    int t = w[n][i];
    int h = add(dn[n][0], add(mul(dn[n][0], f(t, 0)), mul(dn[n][1], f(t, 1))));
    dn[n][1] =
        add(dn[n][1], add(mul(dn[n][0], f(t, 1)), mul(dn[n][1], f(t, 0))));
    dn[n][0] = h;
  }
  dn[n][0] = add(dn[n][0], dn[n][0]);
  dn[n][1] = add(dn[n][1], dn[n][1]);
  dn2[0][0] = dn2[1][0] = 1;
  dn2[0][1] = dn2[1][1] = 0;
  for (int i = 0; i < w[n].size(); i++) {
    int t = w[n][i];
    dn2[0][0] = add(dn2[0][0], mul(f(t, 0), dn2[0][0]));
    int h = add(dn2[1][1], mul(dn2[1][0], f(t, 1)));
    dn2[1][0] = add(dn2[1][0], mul(dn2[1][1], f(t, 1)));
    dn2[1][1] = h;
  }
  dn[n][0] = add(dn[n][0], MOd - dn2[0][0]);
  dn[n][1] = add(dn[n][1], MOd - dn2[1][1]);
  return dn[n][s];
}
int main() {
  memset(dn, -1, sizeof(dn));
  scanf("%d", &a);
  for (int i = 2, j; i <= a; i++) {
    scanf("%d", &j);
    w[j].push_back(i);
  }
  cout << add(f(1, 0), f(1, 1)) << endl;
  return 0;
}

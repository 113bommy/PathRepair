#include <bits/stdc++.h>
const int mod = 1000000007;
const int inf = 1000000009;
const long long INF = 1000000000000000009;
const long long big = 1000000000000000;
const long double eps = 0.000000000000000000001;
using namespace std;
double E[100005], CE[100005], P[100005];
double licz(int x) {
  if (P[x] == 1) return inf;
  return (CE[x] + P[x]) / ((double)1.0 - P[x]);
}
struct cmp {
  bool operator()(int a, int b) const {
    if (E[a] != E[b])
      return E[a] < E[b];
    else
      return a < b;
  }
};
set<int, cmp> S;
double T[1005][1005];
bool O[1005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int a;
      cin >> a;
      T[i][j] = (double)a / 100.0;
    }
    P[i] = 1.0;
  }
  for (int i = 1; i < n; i++) {
    P[i] = (double)1.0 - T[i][n];
    CE[i] = T[i][n];
    E[i] = licz(i);
    S.insert(i);
  }
  O[n] = 1;
  while (true) {
    if (n == 1) break;
    int x = *S.begin();
    if (x == 1) break;
    O[x] = 1;
    for (int i = 1; i <= n; i++) {
      if (O[i]) continue;
      CE[i] += P[i] * T[i][x] * (E[x] + 1);
      P[i] *= ((double)1.0 - T[i][x]);
    }
    S.clear();
    for (int i = 1; i <= n; i++) {
      if (!O[i]) {
        E[i] = licz(i);
        S.insert(i);
      }
    }
  }
  cout.precision(9);
  cout << fixed << E[1];
  return 0;
}

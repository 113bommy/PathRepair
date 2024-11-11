#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2020;
const double EPS = 1e-9;
int N, K;
int deg[MAXN];
long long c[MAXN][MAXN];
long double C(int n, int k) {
  long double ans = 1;
  for (int i = 0; i < k; i++) ans = ans * (n - i) / (i + 1);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(c, -1, sizeof(c));
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      long long x;
      cin >> x;
      if (x != -1) {
        c[i][j] = c[j][i] = x;
        deg[i]++;
        deg[j]++;
      }
    }
  }
  long double ans = 0;
  long double total = C(N, K);
  for (int i = 0; i < N; i++) {
    if (deg[i] < K) continue;
    long double cur = C(deg[i] - 1, K - 1);
    for (int j = 0; j < N; j++)
      if (c[i][j] != -1) ans += c[i][j] * cur / total;
  }
  cout << (long long)(ans + EPS) << endl;
  return 0;
}

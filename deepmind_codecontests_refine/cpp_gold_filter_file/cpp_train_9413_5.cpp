#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int INF = 1 << 30;
const long long LINF = 1ll << 60;
const int BUFFER_SZ = 1 << 15;
const int MOD = 1000 * 1000 * 1000 + 7;
char BUFFER[BUFFER_SZ];
int gi() {
  int x;
  scanf("%d", &x);
  return x;
}
double gd() {
  double x;
  scanf("%lf", &x);
  return x;
}
long long gll() {
  long long x;
  cin >> x;
  return x;
}
vector<int> gvi(int n) {
  vector<int> a;
  while (n-- > 0) a.push_back(gi());
  return a;
}
string gs() {
  scanf("%s", BUFFER);
  return string(BUFFER);
}
template <class T>
void print(vector<T> &x, string format) {
  format += "%c";
  for (int i = 0; i < x.size(); ++i)
    printf(format.c_str(), x[i], i + 1 == x.size() ? '\n' : ' ');
}
int D[64][64];
int main() {
  int n = gi();
  int m = gi();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) D[i][j] = i == j ? 0 : 1 << 20;
  for (int i = 0; i < m; ++i) {
    int a = gi() - 1;
    int b = gi() - 1;
    int c = gi();
    D[a][b] = D[b][a] = min(D[a][b], c);
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (i != j) D[i][j] = D[i][j] * 100 + i;
    }
  vector<int> mn, mx;
  for (int i = 0; i < n; ++i) {
    int mmn = 1 << 30;
    int mmx = -(1 << 30);
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        mmn = min(mmn, D[i][j]);
        mmx = max(mmx, D[i][j]);
      }
    }
    mn.push_back(mmn);
    mx.push_back(mmx);
  }
  int g1 = gi();
  int g2 = gi();
  int s1 = gi();
  int s2 = gi();
  long long dp[51][51][51];
  long long res = 0;
  for (int a = 0; a < n; ++a) {
    for (int b = 0; b < n; ++b) {
      if (a == b || mn[a] >= mx[b]) continue;
      memset((dp), (0), sizeof(dp));
      dp[0][0][0] = 1;
      for (int i = 0; i < n; ++i) {
        int gold = 0;
        int silver = 0;
        int bronse = 0;
        if (i == a)
          gold = 1;
        else if (i == b)
          bronse = 1;
        else {
          if (mn[i] < mn[a]) gold = 1;
          if (mx[i] > mx[b]) bronse = 1;
          for (int k = 0; k < n; ++k)
            if (k != i && D[i][k] > mn[a] && D[i][k] < mx[b]) silver = 1;
        }
        for (int g = 0; g <= i; ++g)
          for (int s = 0; s + g <= i; ++s) {
            int b = i - g - s;
            if (gold) dp[g + 1][s][b] += dp[g][s][b];
            if (silver) dp[g][s + 1][b] += dp[g][s][b];
            if (bronse) dp[g][s][b + 1] += dp[g][s][b];
          }
      }
      for (int g = g1; g <= g2; ++g)
        for (int s = s1; s <= s2; ++s) res += dp[g][s][n - g - s];
    }
  }
  cout << res << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return (x > 0) ? 1 : -1;
}
const unsigned long long hash1 = 201326611;
const unsigned long long hash2 = 50331653;
const int N = 1000000 + 10;
const int M = 2048 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1000000000 + 7;
vector<int> g[N];
int n, m, k, sum[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  char a[N], b[N];
  cin >> a + 1 >> b + 1;
  sum[0] = 0;
  int la = strlen(a + 1);
  int lb = strlen(b + 1);
  for (int i = 1; i <= la; i++) {
    if (a[i] == '1')
      sum[i] = sum[i - 1] + 1;
    else
      sum[i] = sum[i - 1];
  }
  for (int i = 1; i <= lb; i++) {
    if (b[i] == '1') k++;
  }
  int ans = 0;
  for (int i = 1; i <= la; i++) {
    if (la - i < lb) break;
    if ((sum[i + lb - 1] - sum[i - 1]) % 2 == k % 2) ans++;
  }
  cout << ans << endl;
  return 0;
}

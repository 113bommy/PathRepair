#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(NULL));
const long double eps = 1e-9;
const int inf = 1e9;
const int mod = 1e9 + 7;
const long long infinity = 2 * 1e18;
#pragma GCC optimize("O3")
inline int read() {
  int val = 0, sign = 1;
  char ch;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') sign = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) val = val * 10 + ch - '0';
  return sign * val;
}
vector<int> w[1000001];
int a[1000001];
void solve() {
  int n = read();
  for (int i = 0; i < n; i++) {
    int x = read();
    w[x].push_back(i);
    a[i] = x;
  }
  long long ans = 0;
  for (int i = 0; i < 1000001; i++)
    for (int j = 0, pr = -1; j < w[i].size(); pr = w[i][j], j++)
      ans += 2 * (w[i][j] - pr) * (n - w[i][j]) - 1;
  cout << fixed << setprecision(20) << (double)(ans) / (n * 1LL * n) << '\n';
}
int main() {
  int t = 1;
  while (t--) {
    clock_t z = clock();
    solve();
    fprintf(stderr, "Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC),
        fflush(stderr);
  }
}

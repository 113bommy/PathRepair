#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)3e5 + 10, MAXK = (int)1e6 + 10;
long long Tohka;
int n, k, a[MAXN], s[MAXK];
vector<int> v[MAXN];
void Calc(int *b, int n, int *c, int m, int del) {
  for (int i = 1, j = 1, p = 0, s = 0; i <= n; ++i) {
    p = max(p, b[i]);
    s = (s + b[i]) % k;
    for (; j <= m && c[j] < p + del; ++j)
      ;
    v[j - 1].push_back((s - p % k + k) % k);
  }
  for (int j = 1, w = 0; j <= m; ++j) {
    w = (w + c[j]) % k;
    ++s[w];
    for (int i = 0; i < ((int)(v[j]).size()); ++i)
      Tohka += s[(k - v[j][i]) % k];
  }
  for (int j = 1, w = 0; j <= m; ++j) {
    w = (w + c[j]) % k;
    --s[w];
    v[j].clear();
  }
}
void solve(int dep, int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  static int b[MAXN], c[MAXN];
  for (int i = l; i <= mid; ++i) b[i - l + 1] = a[i];
  for (int j = mid + 1; j <= r; ++j) c[j - mid] = a[j];
  reverse(b + 1, b + mid - l + 2);
  Calc(b, mid - l + 1, c, r - mid, 0);
  Calc(c, r - mid, b, mid - l + 1, 1);
  solve(dep + 1, l, mid), solve(dep + 1, mid + 1, r);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  solve(1, 1, n);
  cout << Tohka << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

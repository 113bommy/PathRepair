#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<string> ans;
char s[50];
int ds(int start, int end) {
  int z = 0;
  for (int i = start; i <= end; ++i) z = z * 10 + s[i] - '0';
  return z;
}
void mk(int n) {
  vector<bool> u(10);
  for (int i = 0; i < n; ++i) u[s[i] - '0'] = 1;
  for (int i = 0; i < a.size(); ++i)
    if (!u[a[i]]) return;
  for (int i = 0; i <= min(n - 4, 2); ++i) {
    if (s[0] == '0' && i) continue;
    for (int j = i + 1; j <= min(n - 3, i + 3); ++j) {
      if (s[i + 1] == '0' && j - i > 1) continue;
      for (int k = j + 1; k <= min(n - 2, j + 3); ++k) {
        if (n - k - 1 > 3) continue;
        if (s[j + 1] == '0' && k - j > 1) continue;
        if (s[k + 1] == '0' && n - k - 1 > 1) continue;
        int d1 = ds(0, i);
        int d2 = ds(i + 1, j);
        int d3 = ds(j + 1, k);
        int d4 = ds(k + 1, n - 1);
        if (d1 > 255 || d2 > 255 || d3 > 255 || d4 > 255) continue;
        char st[20];
        sprintf(st, "%d%d%d%d", d1, d2, d3, d4);
        if (strcmp(st, s) != 0) continue;
        sprintf(st, "%d.%d.%d.%d", d1, d2, d3, d4);
        ans.push_back(st);
      }
    }
  }
}
void genpoly(int ind = 0) {
  if (ind > 6) return;
  if (ind > 1) {
    for (int i = 0; i < ind; ++i) s[ind + i] = s[ind - i - 1];
    s[ind * 2] = 0;
    mk(ind * 2);
    if (ind > 2) {
      for (int i = 0; i < ind - 1; ++i) s[ind + i] = s[ind - i - 2];
      s[ind * 2 - 1] = 0;
      mk(ind * 2 - 1);
    }
  }
  for (int i = 0; i < a.size(); ++i) {
    s[ind] = a[i] + '0';
    genpoly(ind + 1);
  }
}
bool solve() {
  ans.clear();
  int n;
  if (scanf("%d", &n) == EOF) return false;
  a.resize(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  genpoly();
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
  return true;
}
int main() {
  solve();
  return 0;
}

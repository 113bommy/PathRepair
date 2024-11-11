#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
bool vst[N][N];
int n, t, a[N], c[N], q[N], mx, p, ind;
map<int, int> m;
map<int, int>::iterator it;
void f(int p, int k) {
  for (int i = p; i < k; i++) c[q[i]]++;
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    m[t]++;
  }
  n = 0;
  for (it = m.begin(); it != m.end(); it++) {
    n++;
    a[n] = it->first;
    c[n] = it->second;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) vst[i][j] = 0;
  mx = 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (vst[i][j]) continue;
      if (i == j && c[i] < 2) continue;
      c[i]--;
      c[j]--;
      q[1] = i;
      q[2] = j;
      p = 1;
      for (int k = 3;; k++) {
        if (k - p + 1 < 3) {
          if (p < k) f(p, k);
          break;
        }
        vst[q[p]][q[p + 1]] = true;
        t = a[q[k - 1]] + a[q[k - 2]];
        ind = lower_bound(a + 1, a + n + 1, t) - a;
        if (ind > n || t != a[ind]) {
          if (p < k) f(p, k);
          break;
        }
        if (c[ind] == 0) {
          for (; p < k; p++) {
            if (a[q[p]] == t && k - p + 1 >= 3 && !vst[q[p]][q[p + 1]]) {
              q[k] = q[p];
              p++;
              break;
            }
            c[q[p]]++;
          }
          if (k - p + 1 < 3 || vst[q[p]][q[p + 1]]) {
            if (p < k) f(p, k);
            break;
          }
        } else {
          q[k] = ind;
          c[ind]--;
          if (k - p + 1 > mx) mx = k - p + 1;
        }
      }
    }
  }
  cout << mx << "\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int x[1024], y[1024], d[1024];
int ans[1024];
int n, m;
map<int, int> all;
bool solve(int s) {
  map<int, int> w;
  for (int i = 0; i < n; i += 2) {
    int t = abs(x[s + i] - x[s + i + 1]) + abs(y[s + i] - y[s + i + 1]) +
            abs(x[s + i + 1] - x[s + i + 2]) + abs(y[s + i + 1] - y[s + i + 2]);
    w[t]++;
  }
  map<int, int>::iterator it;
  for (it = w.begin(); it != w.end(); ++it)
    if (it->second > all[it->first]) return false;
  return true;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < (n); ++i) scanf("%d %d", x + i, y + i);
  for (int i = 0; i < (m); ++i) scanf("%d", d + i);
  for (int i = 0; i < (n); ++i) x[i + n] = x[i], y[i + n] = y[i];
  for (int i = 0; i < (m); ++i) all[d[i]]++;
  for (int s = 0; s < (n); ++s)
    if (solve(s)) {
      puts("YES");
      int k = s;
      for (int i = 0; i < n; i += 2) {
        int t = abs(x[s + i] - x[s + i + 1]) + abs(y[s + i] - y[s + i + 1]) +
                abs(x[s + i + 1] - x[s + i + 2]) +
                abs(y[s + i + 1] - y[s + i + 2]);
        for (int j = 0; j < (m); ++j)
          if (d[j] == t) {
            ans[k++] = j + 1;
            if (k >= n) k = 0;
            ans[k++] = -1;
            if (k >= n) k = 0;
            d[j] = -1;
            break;
          }
      }
      for (int j = 0; j < (n); ++j) printf("%d ", ans[j]);
      puts("");
      return 0;
    }
  puts("NO");
  return 0;
}

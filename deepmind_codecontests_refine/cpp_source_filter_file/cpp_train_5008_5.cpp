#include <bits/stdc++.h>
using namespace std;
const int size = 1e5 + 2;
int ver[size], n, m;
vector<int> kw;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &ver[i]);
  sort(ver, ver + n);
  ver[n] = 1e9;
  for (int i = 0; i < m; i++) {
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    if (a == 1) kw.push_back(b);
  }
  sort(kw.begin(), kw.end());
  m = kw.size();
  int j = 0, ans = m;
  for (int i = 0; i < n; i++) {
    int x = ver[i];
    while (j < m) {
      if (kw[j] < x)
        j++;
      else
        break;
    }
    ans = min(ans, i + m - j);
  }
  printf("%d", ans);
}

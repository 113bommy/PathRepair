#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, ans = 0;
  scanf("%d", &n);
  vector<int> v(n);
  vector<int> m(2 * 1000009);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
    m[v[i]]++;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m.size(); ++i) {
    int col = m[i];
    if (col % 2 != 0)
      col--, m[i] = 1;
    else
      m[i] = 0;
    if (i + 1 < m.size()) m[i + 1] += col / 2;
    if (m[i] == 1) ++ans;
  }
  printf("%d", ans);
}
int main() { solve(); }

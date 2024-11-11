#include <bits/stdc++.h>
using namespace std;
int optimalize(int x) {
  for (int i = 2; i * i <= abs(x); i++)
    if (x % (i * i) == 0) x /= i * i;
  return x;
}
int main(void) {
  int n;
  scanf("%d", &n);
  vector<int> t(n);
  for (int i = 0; i < n; i++) scanf("%d", &t[i]);
  map<int, int> m;
  int x = 1;
  for (int i = 0; i < n; i++) {
    if (t[i] == 0) continue;
    t[i] = optimalize(t[i]);
    if (m.find(t[i]) == m.end()) m[t[i]] = x++;
    t[i] = m[t[i]];
  }
  vector<int> ans(n + 1);
  for (int i = 0; i < n; i++) {
    vector<bool> s(x, false);
    int il = 0;
    for (int j = i; j < n; j++) {
      if (t[j] != 0 && !s[t[j]]) il++;
      s[t[j]] = true;
      ans[max(1, il)]++;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}

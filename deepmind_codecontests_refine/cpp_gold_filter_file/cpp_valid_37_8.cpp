#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> g[100100];
long long ans[100100];
bool extra[100100];
bool poss(int c, int l, int k) {
  int cv = 0;
  for (int i : g[c]) {
    if (i == l) continue;
    if (!poss(i, c, k)) return false;
    cv += extra[i];
  }
  if (cv % k == 0) {
    extra[c] = true;
    return true;
  }
  if ((cv + 1) % k == 0) {
    extra[c] = false;
    return true;
  }
  return false;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    long long ctot = 1;
    for (int i = 1; i < n; i++) {
      int n1, n2;
      scanf(" %d%d", &n1, &n2);
      g[n1].push_back(n2);
      g[n2].push_back(n1);
      ctot *= 2;
      ctot %= 998244353;
    }
    ans[1] = ctot;
    for (int i = n; i > 1; i--) {
      ans[i] = 0;
      if ((n - 1) % i) continue;
      for (int j = i * 2; j <= n; j += i)
        if (ans[j]) ans[i] = 1;
      if (ans[i]) continue;
      for (int j = 1; j <= n; j++) extra[j] = false;
      bool cv = poss(1, -1, i);
      if (cv && extra[1]) ans[i] = 1;
    }
    for (int i = n; i >= 1; i--) {
      for (int j = i * 2; j <= n; j += i) ans[i] -= ans[j];
      ans[i] += 998244353;
      ans[i] %= 998244353;
    }
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) g[i].clear();
  }
}

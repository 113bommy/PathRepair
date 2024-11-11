#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int N = 500500;
const int A = 10000000;
int n, a[N], ans[N][2];
int vis[A];
int main() {
  for (int i = 2; i < A; i++) {
    if (!vis[i]) {
      vis[i] = i;
      for (int j = i + i; j < A; j += i)
        if (!vis[j]) vis[j] = i;
    }
  }
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) scanf("%d", a + i);
  for (int j = (0); j < (n); j++) {
    vector<int> pr;
    int x = a[j];
    while (x > 1) pr.push_back(vis[x]), x /= vis[x];
    sort((pr).begin(), (pr).end());
    pr.resize(unique((pr).begin(), (pr).end()) - pr.begin());
    int d1 = -1, d2 = -1;
    if (((int)(pr).size()) > 1) {
      d2 = pr.back();
      pr.pop_back();
      d1 = 1;
      for (int i = 0; i < ((int)(pr).size()); i++) d1 *= pr[i];
    }
    ans[j][0] = d1;
    ans[j][1] = d2;
  }
  for (int i = 0; i < n; i++) printf("%d ", ans[i][0]);
  puts("");
  for (int i = 0; i < n; i++) printf("%d ", ans[i][1]);
}

#include <bits/stdc++.h>
using namespace std;
vector<int> vec[300000 + 10];
int x[300000 + 10];
bool vst[300000 + 10];
vector<int> used;
int total[300000 + 10];
int GetRandom(int s, int e) {
  long long ret = rand() * rand();
  ret %= (e - s + 1);
  return ret + s;
}
int main() {
  int n, a, q, s, e, k;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", x + i);
    vec[x[i]].push_back(i);
    total[x[i]]++;
  }
  while (q--) {
    scanf("%d %d %d", &s, &e, &k);
    k = (e - s + 1) / k;
    int ans = -1;
    for (int i = 0; i < 70; i++) {
      int ix = GetRandom(s, e);
      int v = x[ix];
      if (ans != -1 && ans <= v) continue;
      if (vst[v]) continue;
      if (total[v] <= k) continue;
      int cnt = upper_bound(vec[v].begin(), vec[v].end(), e) -
                lower_bound(vec[v].begin(), vec[v].end(), s);
      if (cnt > k) ans = (ans == -1) ? v : min(v, ans);
      vst[v] = true;
      used.push_back(v);
    }
    for (auto cur : used) vst[cur] = false;
    used.clear();
    printf("%d\n", ans);
  }
  return 0;
}

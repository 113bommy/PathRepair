#include <bits/stdc++.h>
using namespace std;
vector<long long> vec[60 + 1];
long long v, val[100010];
int n, cur = 1;
int nxt[100010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &v);
    for (long long j = 60; j >= 0; j--)
      if ((1ll << j) & v) {
        vec[j].push_back(v);
        break;
      }
  }
  long long s = 60;
  for (long long j = 60; j >= 0; j--) {
    if (vec[j].size() >= 2) return puts("No"), 0;
    if (vec[j].size() == 1) {
      val[1] = vec[j][0];
      s = j - 1;
      break;
    }
  }
  if (!val[1]) return puts("No"), 0;
  for (long long j = s; j >= 0; j--) {
    if (!vec[j].size()) continue;
    val[++cur] = val[1];
    nxt[cur] = nxt[1];
    nxt[1] = cur;
    val[1] = *vec[j].begin();
    vec[j].erase(vec[j].begin());
    for (int it = nxt[1]; it != 0 && vec[j].size(); it = nxt[it]) {
      if (val[it] & (1ll << j)) {
        nxt[++cur] = nxt[it];
        nxt[it] = cur;
        val[cur] = *vec[j].begin();
        vec[j].erase(vec[j].begin());
        it = cur;
      }
    }
    if (vec[j].size()) return puts("No"), 0;
  }
  puts("Yes");
  for (int it = 1; it != 0; it = nxt[it]) printf("%lld ", val[it]);
  puts("");
  return 0;
}

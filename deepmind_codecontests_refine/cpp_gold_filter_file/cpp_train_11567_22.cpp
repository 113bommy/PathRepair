#include <bits/stdc++.h>
using namespace std;
const int Q = 5;
const long long K = 10000;
long long f[Q];
map<long long, long long> g[Q];
long long ask(long long l, int num, vector<long long> *las = NULL) {
  if (num < 0) return 0;
  if (las == NULL && g[num].count(l)) return g[num][l];
  if (las == NULL && l >= K) return f[num];
  long long res = 0, p = l;
  for (long long i = 1; i <= min(l, K) + 1; i++) {
    p += ask(p, num - 1);
    if (i != min(l, K) + 1) {
      if (las != NULL) las->push_back(p);
      p++;
    }
  }
  return g[num][l] = p - l;
}
int main() {
  f[0] = K;
  for (int i = 1; i < Q; i++) f[i] = f[i - 1] * (K + 1) + K;
  long long l = 1;
  for (int i = Q - 1; i >= 0; i--) {
    vector<long long> list;
    ask(l, i, &list);
    printf("%d ", list.size());
    for (int j = 0; j < list.size(); j++) printf("%lld ", list[j]);
    puts("");
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    if (ans == -1) break;
    if (ans) l = list[ans - 1] + 1;
  }
}

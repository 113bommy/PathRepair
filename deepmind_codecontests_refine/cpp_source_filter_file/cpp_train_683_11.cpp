#include <bits/stdc++.h>
using namespace std;
template <size_t N, size_t M>
struct Suffix_Automata {
  int maxlen[N], trans[N][M], link[N], Size, Last, isclone[N];
  Suffix_Automata() { Size = Last = 1; }
  void Extend(int id) {
    int cur = (++Size), p;
    maxlen[cur] = maxlen[Last] + 1;
    for (p = Last; p && !trans[p][id]; p = link[p]) trans[p][id] = cur;
    if (!p)
      link[cur] = 1;
    else {
      int q = trans[p][id];
      if (maxlen[q] == maxlen[p] + 1)
        link[cur] = q;
      else {
        int clone = (++Size);
        maxlen[clone] = maxlen[p] + 1;
        memcpy(trans[clone], trans[q], sizeof(trans[q]));
        link[clone] = link[q];
        for (; p && trans[p][id] == q; p = link[p]) trans[p][id] = clone;
        link[cur] = link[q] = clone;
        isclone[clone] = true;
      }
    }
    isclone[cur] = false;
    Last = cur;
  }
  int cnt[N], in[N];
  vector<int> G[N];
  long long calc() {
    long long res = 0;
    for (int i = 1; i <= Size; i++) cnt[i] = !isclone[i];
    for (int i = 1; i <= Size; i++) {
      G[i].clear();
      G[i].push_back(link[i]);
      ++in[link[i]];
    }
    queue<int> Q;
    for (int i = 1; i <= Size; i++) {
      if (!in[i]) {
        Q.push(i);
      }
    }
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (int v : G[u]) {
        cnt[v] += cnt[u];
        if (!(--in[v])) {
          Q.push(v);
        }
      }
    }
    for (int i = 1; i <= Size; i++) {
      res += 1LL * cnt[i] * cnt[i] * (maxlen[i] - maxlen[link[i]]);
    }
    return res;
  }
};
Suffix_Automata<300000, 26> SAM;
char s[300000];
int main() {
  int T;
  scanf("%d", &T);
  for (int _ = 0; _ < T; _++) {
    memset(SAM.trans, 0, sizeof(SAM.trans));
    SAM.Last = SAM.Size = 1;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
      SAM.Extend(s[i]);
    }
    printf("%lld\n", SAM.calc());
  }
  return 0;
}

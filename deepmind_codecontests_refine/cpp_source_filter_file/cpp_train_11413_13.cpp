#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, w;
  int idx;
  friend bool operator<(const edge& p1, const edge& p2) { return p1.w < p2.w; }
};
const int maxn = 100001;
int F[maxn];
int num[maxn];
int getroot(int v) { return F[v] == v ? v : F[v] = getroot(F[v]); }
int n;
edge es[maxn];
int elist[maxn + maxn][2];
int eh[maxn];
int cnte;
int v[maxn], numv;
int fa[maxn], cnt[maxn];
vector<int> seq, stk;
vector<int> ans;
long long best;
void addedge(int a, int edgeIdx) {
  v[numv] = a;
  elist[cnte][0] = edgeIdx;
  elist[cnte][1] = eh[a];
  eh[a] = cnte++;
  numv++;
}
void FF(int v) {
  stk.clear();
  stk.push_back(v);
  seq.clear();
  int cur, eIdx, next;
  fa[v] = -2;
  while (!stk.empty()) {
    cur = stk.back();
    if (eh[cur] < 0) {
      stk.pop_back();
      if (fa[cur] != -2) {
        eIdx = fa[cur];
        next = es[eIdx].u ^ es[eIdx].v ^ cur;
        cnt[eIdx] += num[cur];
        num[next] += num[cur];
        F[cur] = next;
      }
      continue;
    }
    eIdx = elist[eh[cur]][0];
    eh[cur] = elist[eh[cur]][1];
    next = es[eIdx].u ^ es[eIdx].v ^ cur;
    if (fa[next] != -1) {
      fa[cur] = eIdx;
    } else {
      stk.push_back(next);
      seq.push_back(eIdx);
      fa[next] = -2;
    }
  }
  long long val;
  for (int i = 0; i < seq.size(); i++) {
    val = (long long)cnt[seq[i]] * (num[v] - cnt[seq[i]]);
    val <<= 1;
    if (val > best) {
      ans.clear();
      ans.push_back(es[seq[i]].idx);
      best = val;
    } else if (val == best) {
      ans.push_back(es[seq[i]].idx);
    }
  }
}
void calc() {
  for (int i = 0; i < numv; i++) {
    if (fa[v[i]] == -1) FF(v[i]);
  }
  for (int i = 0; i < numv; i++) fa[v[i]] = -1;
}
int main() {
  scanf("%d", &n);
  int a, b, c;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d%d", &a, &b, &c);
    a--, b--;
    es[i].u = a, es[i].v = b, es[i].w = c;
    es[i].idx = i + 1;
    cnt[i] = 0;
  }
  sort(es, es + n - 1);
  for (int i = 0; i < n; i++) {
    F[i] = i;
    num[i] = 1;
    fa[i] = -1;
    eh[i] = -1;
  }
  best = 0;
  for (int i = 0; i < n - 1;) {
    numv = cnte = 0;
    int j;
    for (j = i; j < n - 1 && es[j].w == es[i].w; j++)
      ;
    for (int k = i; k < j; k++) {
      es[k].u = getroot(es[k].u);
      es[k].v = getroot(es[k].v);
      addedge(es[k].u, k);
      addedge(es[k].v, k);
    }
    calc();
    i = j;
  }
  cout << best << ' ' << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << endl;
  return 0;
}

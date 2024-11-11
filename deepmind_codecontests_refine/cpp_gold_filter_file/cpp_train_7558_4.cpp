#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100001;
const int SQRT_N = sqrt(MAX_N);
const int LOG_N = 17;
struct Query {
  int idx;
  int l, r;
  int extra;
  long long answer;
} queries[MAX_N];
int n, q;
bool gender[MAX_N];
int f[MAX_N];
vector<int> v[MAX_N];
int first[MAX_N], second[MAX_N];
int linearTree[2 * MAX_N], idx;
int pr[MAX_N][LOG_N], level[MAX_N];
int cnt[MAX_N][2];
bool added[2 * MAX_N];
long long answer;
pair<int, int> fVals[MAX_N];
void readTree() {
  int x, y;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &gender[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
    fVals[i] = {f[i], i};
  }
  int compressionIdx = 0;
  sort(fVals + 1, fVals + n + 1);
  f[fVals[1].second] = compressionIdx;
  for (int i = 2; i <= n; i++) {
    if (fVals[i].first != fVals[i - 1].first) compressionIdx++;
    f[fVals[i].second] = compressionIdx;
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
}
void initTree(int ver, int parent) {
  pr[ver][0] = parent;
  linearTree[idx] = ver;
  first[ver] = idx++;
  if (parent == -1)
    level[ver] = 0;
  else
    level[ver] = level[parent] + 1;
  for (int i = 0; i < v[ver].size(); i++)
    if (v[ver][i] != parent) initTree(v[ver][i], ver);
  linearTree[idx] = ver;
  second[ver] = idx++;
}
void initParents() {
  for (int i = 1; i < LOG_N; i++)
    for (int j = 1; j <= n; j++)
      if (pr[j][i - 1] == -1)
        pr[j][i] = -1;
      else
        pr[j][i] = pr[pr[j][i - 1]][i - 1];
}
int findLCA(int p, int q) {
  if (level[p] > level[q]) swap(p, q);
  int pw = LOG_N - 1;
  while (level[p] != level[q]) {
    if (level[pr[q][pw]] >= level[p]) q = pr[q][pw];
    pw--;
  }
  pw = LOG_N - 1;
  while (pw != -1) {
    if (pr[p][pw] != pr[q][pw]) {
      p = pr[p][pw];
      q = pr[q][pw];
    }
    pw--;
  }
  if (p != -1) p = pr[p][0];
  return p;
}
void readQueries() {
  int x, y;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x, &y);
    if (first[x] > first[y]) swap(x, y);
    if (first[y] < second[x]) {
      queries[i].l = first[x];
      queries[i].r = first[y];
      queries[i].extra = -1;
    } else {
      queries[i].l = second[x];
      queries[i].r = first[y];
      queries[i].extra = findLCA(x, y);
    }
    queries[i].idx = i;
    queries[i].answer = 0LL;
  }
}
bool cmp(Query el1, Query el2) {
  if (el1.l / SQRT_N != el2.l / SQRT_N) return el1.l / SQRT_N < el2.l / SQRT_N;
  return el1.r < el2.r;
}
bool cmp2(Query el1, Query el2) { return el1.idx < el2.idx; }
void toggle(int x) {
  if (added[x]) {
    answer -= cnt[f[x]][gender[x] ^ 1];
    cnt[f[x]][gender[x]]--;
  } else {
    answer += cnt[f[x]][gender[x] ^ 1];
    cnt[f[x]][gender[x]]++;
  }
  added[x] ^= 1;
}
void Mo() {
  sort(queries + 1, queries + q + 1, cmp);
  int l, r;
  l = r = 0;
  toggle(linearTree[0]);
  for (int i = 1; i <= q; i++) {
    while (l > queries[i].l) {
      l--;
      toggle(linearTree[l]);
    }
    while (r < queries[i].r) {
      r++;
      toggle(linearTree[r]);
    }
    while (l < queries[i].l) {
      toggle(linearTree[l]);
      l++;
    }
    while (r > queries[i].r) {
      toggle(linearTree[r]);
      r--;
    }
    if (queries[i].extra != -1) {
      toggle(queries[i].extra);
      queries[i].answer = answer;
      toggle(queries[i].extra);
    } else
      queries[i].answer = answer;
  }
  sort(queries + 1, queries + q + 1, cmp2);
}
void print() {
  for (int i = 1; i <= q; i++) printf("%lld\n", queries[i].answer);
}
void debugPrint() {
  printf("\nvertex info:\n");
  for (int i = 1; i <= n; i++)
    printf("vertex %d level %d frist %d second %d\n", i, level[i], first[i],
           second[i]);
}
int main() {
  readTree();
  initTree(1, -1);
  initParents();
  readQueries();
  Mo();
  print();
}

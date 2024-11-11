#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010, d = 0;
int N, Q, M, uf[MAXN * 2];
void init() {
  for (int i = 1; i <= 2 * N; ++i) {
    uf[i] = -1;
  }
}
int find(int n) {
  if (uf[n] < 0) {
    return n;
  } else {
    uf[n] = find(uf[n]);
    return uf[n];
  }
}
void merge(int a, int b) {
  int pa = find(a);
  int pb = find(b);
  if (pa == pb) {
    return;
  } else if (uf[pa] == uf[pb]) {
    uf[pa]--;
    uf[pb] = pa;
  } else if (uf[pa] < uf[pb]) {
    uf[pb] = pa;
  } else {
    uf[pa] = pb;
  }
}
pair<pair<int, int>, pair<int, int> > edges[MAXN * (MAXN - 1) / 2];
int counterpart[MAXN];
void reset() {
  init();
  for (int i = 1; i <= 2 * N; ++i) {
    counterpart[i] = -1;
  }
}
void print_uf() {
  for (int i = 1; i <= 2 * N; ++i) {
    printf("\t%d belongs to group %d with counterpart %d\n", i, find(i),
           counterpart[find(i)]);
  }
}
int main() {
  scanf("%d %d %d", &N, &M, &Q);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edges[i] = make_pair(make_pair(c, i + 1), make_pair(a, b));
  }
  sort(edges, edges + M);
  for (int i = 0; i < Q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    reset();
    int answer = -1;
    for (int j = M - 1; j >= 0; --j) {
      if (edges[j].first.second < l or edges[j].first.second > r) {
        continue;
      }
      int a = edges[j].second.first;
      int b = edges[j].second.second;
      int pa = find(a);
      int pb = find(b);
      if (counterpart[pa] < 0) {
        counterpart[pa] = N + pa;
        counterpart[N + pa] = pa;
      }
      if (counterpart[pb] < 0) {
        counterpart[pb] = N + pb;
        counterpart[N + pb] = pb;
      }
      if (pb == pa) {
        answer = edges[j].first.first;
        break;
      } else {
        merge(pb, counterpart[pa]);
        merge(pa, counterpart[pb]);
      }
    }
    printf("%d\n", answer);
  }
  return 0;
}

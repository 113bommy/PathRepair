#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 2e5 + 5, M = N * 2, Q = 2e5;
int n, q, sqr;
long long cnt, ans[Q], a[N];
long long freq[1000 * 1000 + 5];
int st, en;
int qst[Q], qen[Q], sorted[Q];
void add(long long x) {
  long long last = freq[x]++;
  cnt += (((freq[x] * freq[x]) - (last * last)) * x);
}
void rmv(long long x) {
  long long last = freq[x]--;
  cnt += (((freq[x] * freq[x]) - (last * last)) * x);
}
void update_st_en(int qi) {
  while (en <= qen[qi]) add(a[en++]);
  while (en > qen[qi] + 1) rmv(a[--en]);
  while (st > qst[qi]) add(a[--st]);
  while (st < qst[qi]) rmv(a[st++]);
}
int main() {
  scanf("%d%d", &n, &q);
  sqr = sqrt(n);
  for (int i = 0; i < n; ++i) scanf("%lld", a + i);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", qst + i, qen + i);
    --qst[i];
    --qen[i];
    sorted[i] = i;
  }
  sort(sorted, sorted + q, [](int i, int j) {
    return make_pair(qst[i] / sqr, qen[i]) < make_pair(qst[j] / sqr, qen[j]);
  });
  for (int i = 0; i < q; ++i) {
    int qi = sorted[i];
    update_st_en(qi);
    ans[qi] = cnt;
  }
  for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
  return 0;
}

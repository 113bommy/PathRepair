#include <bits/stdc++.h>
using namespace std;
struct Query {
  int idx;
  int start, skip;
  long long ans;
  Query() : idx(0), start(0), skip(0), ans(0) {}
  bool operator<(const Query &q) const {
    return skip != q.skip ? skip < q.skip : start < q.start;
  }
};
bool cmp_idx(const Query &q1, const Query &q2) { return q1.idx < q2.idx; }
const int MAX = 300010;
const int SQR = 566;
int w[MAX];
Query query[MAX];
long long sum[SQR][SQR];
long long sum_dummy(int start, int skip, int N) {
  long long ans = 0;
  for (; start < N; start += skip) ans += (long long)w[start];
  return ans;
}
long long sum_smart(int start, int skip, int N) {
  long long ans = 0;
  const int idx = start % skip;
  int bucket = start / SQR;
  for (int i = start; i < N && i / SQR == bucket; i += skip)
    ans += (long long)w[i];
  ++bucket;
  for (; bucket < SQR; ++bucket) ans += sum[idx][bucket];
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int _n(n), i(0); i < _n; i++) scanf("%d", &w[i]);
  int p;
  cin >> p;
  for (int _n(p), i(0); i < _n; i++) {
    scanf("%d%d", &query[i].start, &query[i].skip);
    query[i].start--;
    query[i].idx = i;
  }
  sort(query, query + p);
  int total_counter = 0;
  for (int _n(SQR + 1), skip(1); skip < _n; skip++) {
    if (total_counter >= p) break;
    if (query[total_counter].skip > skip) continue;
    memset((sum), (0), sizeof(sum));
    for (int _n(n), i(0); i < _n; i++)
      sum[i % skip][i / SQR] += (long long)w[i];
    while (total_counter < p && query[total_counter].skip == skip) {
      query[total_counter].ans =
          sum_smart(query[total_counter].start, query[total_counter].skip, n);
      total_counter++;
    }
  }
  while (total_counter < p) {
    query[total_counter].ans =
        sum_dummy(query[total_counter].start, query[total_counter].skip, n);
    total_counter++;
  }
  vector<long long> a(p);
  for (int _n(p), i(0); i < _n; i++) a[query[i].idx] = query[i].ans;
  for (int _n(p), i(0); i < _n; i++) {
    printf("%d\n", a[i]);
  }
  return 0;
}

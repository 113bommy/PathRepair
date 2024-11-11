#include <bits/stdc++.h>
using namespace std;
struct query {
  int start, jump, idx;
  long long ret;
};
int bucket_size;
int N;
int M;
int a[1 << 19];
query q[1 << 19];
long long sum[600][600];
void scan() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d", a + i);
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &q[i].start, &q[i].jump);
    --q[i].start;
    q[i].idx = i;
  }
}
bool f_jump(query t1, query t2) { return t1.jump < t2.jump; }
bool f_idx(query t1, query t2) { return t1.idx < t2.idx; }
long long get_ans_fast(int start, int jump) {
  long long ret = 0;
  int ost = start % jump;
  int idx = start / bucket_size + 1;
  for (int i = start; i < N && i < idx * bucket_size; i += jump) ret += a[i];
  while (idx * bucket_size < N) ret += sum[idx++][ost];
  return ret;
}
long long get_ans_slow(int start, int jump) {
  long long ret = 0;
  for (start; start < N; start += jump) ret += a[start];
  return ret;
}
void solve() {
  bucket_size = sqrt(N);
  sort(q, q + M, f_jump);
  int last = N;
  for (int i = 0; i < M; ++i) {
    if (q[i].jump > bucket_size) {
      last = i;
      break;
    }
    int k = 0;
    if (!i)
      k = 1;
    else if (q[i].jump != q[i - 1].jump)
      k = 1;
    if (k) {
      memset(sum, 0, sizeof(sum));
      for (int j = 0; j < N; ++j) sum[j / bucket_size][j % q[i].jump] += a[j];
    }
    q[i].ret = get_ans_fast(q[i].start, q[i].jump);
  }
  for (last; last < M; ++last)
    q[last].ret = get_ans_slow(q[last].start, q[last].jump);
  sort(q, q + M, f_idx);
  for (int i = 0; i < M; ++i) printf("%I64d\n", q[i].ret);
}
int main() {
  scan();
  solve();
}

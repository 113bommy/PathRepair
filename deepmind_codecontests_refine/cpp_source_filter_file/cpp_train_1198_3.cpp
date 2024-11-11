#include <bits/stdc++.h>
using namespace std;
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
int n, m, k;
long long A[1000000 + 10], ans, sltn[1000000 + 10];
int freq[1000000 + 10], bucket_size = sqrt(1e5);
struct data {
  unsigned st, ed, idx, l_bucket;
  bool even;
  data(unsigned a, unsigned b, unsigned i) {
    st = a, ed = b, idx = i;
    l_bucket = st / bucket_size;
    if (l_bucket & 1)
      even = false;
    else
      even = true;
  }
  data() {}
};
vector<data> Q;
inline bool cmp(data a, data b) {
  if (a.l_bucket == b.l_bucket) {
    if (a.even)
      return a.ed < b.ed;
    else
      return a.ed > b.ed;
  }
  return a.l_bucket < b.l_bucket;
}
inline void add(unsigned idx) {
  ans += freq[A[idx] ^ k];
  freq[A[idx]]++;
}
inline void rmv(unsigned idx) {
  freq[A[idx]]--;
  ans -= freq[A[idx] ^ k];
}
void Mo() {
  sort(Q.begin(), Q.end(), cmp);
  ans = 0;
  add(1);
  unsigned l = 1, r = 1;
  for (unsigned i = 0; i < Q.size(); i++) {
    while (l < Q[i].st) rmv(l), l++;
    while (l > Q[i].st) l--, add(l);
    while (r < Q[i].ed) r++, add(r);
    while (r > Q[i].ed) rmv(r), r--;
    sltn[Q[i].idx] = ans;
  }
}
int main() {
  int i, j, cs, t;
  scanf("%d %d %d", &n, &m, &k);
  for (i = 1; i <= n; i++) scanf("%lld", &A[i]);
  long long nw = 0;
  for (i = 1; i <= n; i++) A[i] = A[i - 1] ^ A[i];
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &j, &t);
    j--;
    Q.push_back(data(j, t, i));
  }
  Mo();
  for (i = 1; i <= m; i++) printf("%lld\n", sltn[i]);
  return 0;
}

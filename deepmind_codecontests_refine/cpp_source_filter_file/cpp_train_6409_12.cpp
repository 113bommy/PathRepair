#include <bits/stdc++.h>
using namespace std;
struct data {
  long long cost, cnt;
  bool operator<(const data &p) const { return cost > p.cost; }
  data() {}
  data(long long a, long long b) {
    cnt = a;
    cost = b;
  }
};
long long A[200007], B[200007], C[200007], D[200007];
long long x, s;
long long n, m, k;
multiset<long long> st;
long long ptr;
vector<data> vec;
void init() {
  for (long long i = 0; i < m + 1; i++) vec.push_back(data(A[i], B[i]));
  sort(vec.begin(), vec.end());
  for (auto u : vec) st.insert(u.cnt);
  ptr = 0;
}
void remove(long long val) {
  while (ptr < vec.size() && vec[ptr].cost > val)
    st.erase(st.find(vec[ptr++].cnt));
}
long long solve(long long val) {
  if (st.size() == 0) return (1LL << 60LL);
  multiset<long long>::iterator it;
  it = st.begin();
  return *it * val;
}
int main() {
  scanf("%lld %lld %lld", &n, &m, &k);
  scanf("%lld %lld", &x, &s);
  for (long long i = 1; i <= m; i++) scanf("%lld", &A[i]);
  for (long long i = 1; i <= m; i++) scanf("%lld", &B[i]);
  A[0] = x;
  for (long long i = 1; i <= k; i++) scanf("%lld", &C[i]);
  for (long long i = 1; i <= k; i++) scanf("%lld", &D[i]);
  init();
  long long ret = (1LL << 60LL);
  for (long long i = 0; i < k + 1; i++) {
    long long left = s - D[i];
    if (left < 0) continue;
    long long rm = n - C[i];
    remove(left);
    ret = min(ret, solve(rm));
  }
  cout << ret << endl;
  return 0;
}

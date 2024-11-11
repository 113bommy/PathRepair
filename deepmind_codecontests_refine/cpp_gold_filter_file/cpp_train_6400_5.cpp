#include <bits/stdc++.h>
using namespace std;
class C_ {};
template <typename T>
C_& operator<<(C_& __m, const T& __s) {
  if (!1) cerr << "\E[91m" << __s << "\E[0m";
  return __m;
}
C_ merr;
struct __s {
  __s() {
    if (1) {
      ios_base::Init i;
      cin.sync_with_stdio(0);
      cin.tie(0);
    }
  }
  ~__s() {
    merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  }
} __S;
int ST[22][500055];
int A[500055];
int L[500055];
vector<int> I[500055];
map<int, int> mp;
int mlen;
int getidx(int x) {
  if (mp.find(x) == mp.end()) {
    mp[x] = mlen++;
  }
  return mp[x];
}
void build(int n) {
  for (int i = 0; i < n; i++) {
    ST[0][i] = L[i];
  }
  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 0; j < n; j++) {
      ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
    }
  }
}
int LOG[500055];
int query_st(int l, int r) {
  int len = r - l + 1;
  int lg = LOG[len];
  return min(ST[lg][l], ST[lg][r - (1 << lg) + 1]);
}
int n, m;
inline int query(int l, int r) {
  int q1 = query_st(l, r);
  while (1) {
    if (q1 >= r - l + 1) return -1;
    int q2 = query_st(l + q1, r);
    if (q2 == q1) return q1;
    q1 = q2;
  }
}
int main(void) {
  for (int i = 1; i < 500055; i++) {
    LOG[i] = (int)log2(i);
  }
  for (int i = 0; i < 22; i++) {
    for (int j = 0; j < 500055; j++) {
      ST[i][j] = 1000000000;
    }
  }
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    A[i] = getidx(a);
    I[A[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    int a = A[i];
    vector<int>::iterator it;
    if (I[a][0] == i) {
      L[i] = 1000000000;
    } else {
      it = lower_bound(I[a].begin(), I[a].end(), i);
      it--;
      L[i] = i - (*it);
    }
  }
  build(n);
  merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  for (int i = 0; i < m; i++) {
    int l, r, q;
    scanf("%d%d", &l, &r);
    q = query(l - 1, r - 1);
    printf("%d\n", q);
  }
  return 0;
}

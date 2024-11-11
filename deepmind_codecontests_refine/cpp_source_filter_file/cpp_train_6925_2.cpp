#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
struct gs {
  int k, p;
  bool operator<(const gs &r) const { return p != r.p ? p < r.p : k > r.k; }
} e[1 << 18];
int E, N, L, a, b;
set<int> S;
bool cp(gs a, gs b) { return a.k < b.p; }
long long fc(int K, long long p) {
  auto l(S.lower_bound(K));
  if (l == S.end()) return 0;
  long long q(*l), f(min(*l - K, L));
  if (l == S.begin()) return f * p;
  --l;
  if (q - *l <= L) return 0;
  if (K - *l >= L) return f * p;
  return max(0ll, f - L + K - *l) * p;
}
long long sl() {
  sort(e, e + N, cp);
  long long h(0), T(0);
  for (int i(0); i < N; i++)
    if (e[i].k > h + L)
      return -1;
    else
      h = e[i].k;
  sort(e, e + N);
  for (int i(0); i < N; i++) {
    T += fc(e[i].k, e[i].p);
    S.insert(e[i].k);
  }
  return T;
}
int main(void) {
  scanf("%d%d%d", &E, &L, &N);
  for (int i(0); i < N; i++) scanf("%d%d", &a, &b), e[i] = {a, b};
  e[N++] = {E, 0};
  e[N++] = {0, 0};
  printf("%lld\n", sl());
  return 0;
}

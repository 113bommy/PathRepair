#include <bits/stdc++.h>
using namespace std;
int N, a, b, Q;
long long W[(300000)], S[(300000)], O[(300000)];
map<pair<int, int>, vector<pair<int, int> > > M;
void pro(int t, int b, long long* g, int& l) {
  *g = 0, l = 1;
  while (b < N) {
    long long S = W[b] + g[l - 1];
    g[l++] = S, b += t;
  }
}
int main() {
  scanf("%d", &N);
  for (int i(0); i < N; i++) scanf("%lld", W + i);
  scanf("%d", &Q);
  for (int i(0); i < Q; i++)
    scanf("%d%d", &a, &b), --a, M[{b, a % b}].push_back({a, i});
  for (auto& h : M) {
    pro(h.first.first, h.first.second, S, a);
    for (auto& w : h.second)
      O[w.second] = S[a - 1] - S[w.first / h.first.first];
  }
  for (int i(0); i < Q; i++) printf("%lld\n", O[i]);
}

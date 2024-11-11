#include <bits/stdc++.h>
using namespace std;
void _fill_int(int* p, int val, int rep) {
  int i;
  for (i = 0; i < rep; i++) p[i] = val;
}
int GETi() {
  int i;
  scanf("%d", &i);
  return i;
}
template <class T>
T sqr(T val) {
  return val * val;
}
int N, Q;
int V[100001], C[100001];
signed long long MA;
signed long long CM[100001];
signed long long A, B;
int MC1, MC2;
void solve() {
  int f, r, i, j, k, l, cur, tar, ret, loop;
  int res, x, y;
  signed long long c;
  scanf("%d%d", &N, &Q);
  ;
  for (i = 0; i < N; i++) V[i] = GETi();
  for (i = 0; i < N; i++) C[i] = GETi();
  for (i = 0; i < Q; i++) {
    A = GETi();
    B = GETi();
    fill(CM, CM + 100001, -(1LL << 60));
    CM[0] = 0;
    MA = MC1 = MC2 = 0;
    for (x = 0; x < N; x++) {
      if (MC1 == C[x])
        c = max(CM[MC1] + V[x] * A, CM[MC2] + V[x] * B);
      else
        c = max(CM[MC1] + V[x] * B, CM[C[x]] + V[x] * A);
      if (c > CM[C[x]]) {
        CM[C[x]] = c;
        if (MC1 != C[x] && MC2 != C[x]) {
          if (c >= C[MC1]) {
            MC2 = MC1;
            MC1 = C[x];
          } else if (c >= C[MC2]) {
            MC2 = C[x];
          }
        } else if (MC2 == C[x]) {
          if (CM[MC2] > CM[MC1]) swap(MC1, MC2);
        }
      }
      MA = max(MA, c);
    }
    printf("%lld\n", MA);
  }
  return;
}
int main(int argc, char** argv) {
  if (argc > 1) freopen(argv[1], "r", stdin);
  solve();
  return 0;
}

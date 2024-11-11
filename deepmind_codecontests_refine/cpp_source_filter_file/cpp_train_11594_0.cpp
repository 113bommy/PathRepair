#include <bits/stdc++.h>
using namespace std;
const long long NMAX = 110;
int N, K, S;
vector<long long> V;
long long Fib[NMAX], Sum[NMAX];
int main() {
  scanf("%I64d %i", &S, &K);
  Fib[1] = Sum[1] = N = 1;
  for (int i = 2;; ++i) {
    Fib[i] = Sum[i - 1] - Sum[max(0, i - K - 1)];
    if (Fib[i] >= 1LL * S) break;
    N++;
    Sum[i] = Sum[i - 1] + Fib[i];
  }
  for (int i = N; i; --i)
    if (Fib[i] <= S) V.push_back(Fib[i]), S -= Fib[i];
  while (V.size() < 2) V.push_back(0);
  printf("%i\n", V.size());
  for (long long i = 0; i < V.size(); ++i) printf("%i ", V[i]);
}

#include <bits/stdc++.h>
using namespace std;
int N, L, T;
int A[1000002];
long long result;
int main() {
  cin >> N >> L >> T;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  T *= 2;
  int tours = T / L;
  result += 1LL * tours * N * (N - 1);
  T %= L;
  for (int i = 1; i <= N; ++i) {
    if (A[N] - A[i] <= T) {
      result += N - i;
      int step = (1 << 20), resnow;
      for (resnow = 0; step; step >>= 1)
        if (resnow + step < i && L - A[i] + A[resnow + step] <= T)
          resnow += step;
      result += resnow;
    } else {
      int step = (1 << 20), resnow;
      for (resnow = i; step; step >>= 1)
        if (resnow + step <= N && A[resnow + step] - A[i] <= T) resnow += step;
      result += resnow - i;
    }
  }
  cout << result / 4;
  if (result % 4 == 1) cout << ".25";
  if (result % 4 == 2) cout << ".5";
  if (result % 4 == 3) cout << ".75";
  cout << '\n';
}

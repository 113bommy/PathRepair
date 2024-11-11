#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const int MOD = 1000000007;
int F[100007], B[100007], FP[100007], TRB[100007];
int main(int argc, const char **argv) {
  int N, M, T;
  while (cin >> N >> M) {
    for (int i = 0; i <= 100001; ++i) F[i] = B[i] = 0;
    bool amg = false, imp = false;
    for (int i = 1; i <= N; ++i) {
      cin >> T;
      FP[T] = i;
      F[T]++;
    }
    for (int i = 1; i <= M; ++i) {
      cin >> T;
      TRB[i] = T;
      B[T]++;
    }
    for (int i = 1; i <= 100001; ++i) {
      if (imp) break;
      if ((F[i] == 0 && B[i] != 0)) {
        imp = true;
        break;
      }
      if (F[i] > 1) {
        amg = true;
      }
    }
    if (imp) {
      cout << "Impossible" << endl;
      continue;
    }
    if (amg) {
      cout << "Ambiguity" << endl;
      continue;
    }
    cout << "Possible" << endl;
    for (int i = 1; i <= M; ++i) {
      cout << FP[TRB[i]] << " \n"[i == M];
    }
  }
  return 0;
}

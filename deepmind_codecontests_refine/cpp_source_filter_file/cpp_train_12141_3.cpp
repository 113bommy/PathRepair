#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
double T[200000];
char S[200000];
int main() {
  int N;
  scanf("%d%s", &N, S);
  for (int i = 0; i < (N); ++i) {
    T[i] = (S[i] - '0');
  }
  int K = N;
  for (int t = 0; t < (25); ++t) {
    K = N;
    for (int p = (2); p < (N); ++p)
      if (K % p == 0) {
        for (int i = 0; i < (N / p); ++i) {
          double s = 0;
          for (int j = 0; j < (p); ++j) s += T[j * (N / p) + i];
          for (int j = 0; j < (p); ++j) T[j * (N / p) + i] -= s / p;
        }
        while (K % p == 0) K /= p;
        ;
      }
  }
  bool ok = true;
  for (int i = 0; i < (N); ++i) ok = ok && abs(T[i]) < 1e-9;
  printf(ok ? "Yes\n" : "No\n");
}

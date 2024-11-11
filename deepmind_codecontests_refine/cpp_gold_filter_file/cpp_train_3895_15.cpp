#include <bits/stdc++.h>
using namespace std;
int T;
long long A, N, P, H;
void setResult(long long x) {
  if (x <= H)
    puts("YES");
  else
    puts("NO");
}
int main() {
  for (scanf("%d", &T); T; T--) {
    cin >> A >> N >> P >> H;
    A %= P;
    if (A * N < P) {
      setResult(A);
      continue;
    } else
      while (1) {
        long long floorId = A * N / P;
        long long E = P / A * A;
        long long MO = A * N % P % A;
        long long EXPECTED = MO + (E - MO) / A * A;
        long long RECEIVED = A * N % P;
        long long a, n, p;
        a = E + A - P;
        n = floorId - ((EXPECTED <= RECEIVED) ? 0 : 1);
        p = A;
        A = a;
        N = n;
        P = p;
        if (A * N < P) {
          setResult(max(A, P - A * N));
          break;
        }
      }
  }
}

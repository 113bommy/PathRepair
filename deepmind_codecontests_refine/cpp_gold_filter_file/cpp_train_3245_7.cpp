#include <bits/stdc++.h>
using namespace std;
template <class R>
inline void Readin(R &K) {
  K = 0;
  bool F = false;
  char C = getchar();
  while (C < '0' or C > '9') {
    if (C == '-') F = true;
    C = getchar();
  }
  while (C <= '9' and C >= '0')
    K = (K << 1) + (K << 3) + C - '0', C = getchar();
  if (F) K = -K;
}
template <class R>
inline void Checkmax(R &A, R B) {
  if (A < B) A = B;
}
template <class R>
inline void Checkmin(R &A, R B) {
  if (A > B) A = B;
}
int N, K;
int S[1005];
int main() {
  Readin(N);
  Readin(K);
  for (register int i = 0; ++i <= N;) {
    int A;
    Readin(A);
    ++S[A];
  }
  int Ans = 0, Cup = N + 1 >> 1;
  for (register int i = 0; ++i <= K;) {
    while (Cup and S[i] >= 2) {
      Ans += 2;
      S[i] -= 2;
      --Cup;
    }
  }
  for (register int i = 0; ++i <= K;) {
    if (Cup and S[i]) {
      --Cup;
      ++Ans;
    }
  }
  return not printf("%d\n", Ans);
}

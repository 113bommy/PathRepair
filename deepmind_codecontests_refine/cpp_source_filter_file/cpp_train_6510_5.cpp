#include <bits/stdc++.h>
using namespace std;
int N, M, A[200005], B[200005], C, x, y, m1 = 0, m2 = 0, I;
template <class T>
inline void read(T &g) {
  g = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) g = (g << 3) + (g << 1) + (c & 15), c = getchar();
}
int main() {
  read(N);
  for (int i = 1; i <= N; ++i) {
    read(A[i]);
  }
  sort(A + 1, A + N + 1);
  read(M);
  for (int i = 1; i <= M; ++i) {
    read(B[i]);
  }
  for (int i = 1; i <= M; ++i) {
    read(C);
    x = (int)(upper_bound(A + 1, A + N + 1, B[i]) - A) -
        (int)(lower_bound(A + 1, A + N + 1, B[i]) - A);
    y = (int)(upper_bound(A + 1, A + N + 1, C) - A) -
        (int)(lower_bound(A + 1, A + N + 1, C) - A);
    if (x > m1 || (x == m1 && y > m2)) {
      I = i;
      m1 = x, m2 = y;
    }
  }
  printf("%d", I);
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int M, N, x, a[400010], mini = 0;
  cin >> M >> N;
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= M; i++) {
    scanf("%d", &x);
    a[x % N]++;
    if (x % N != mini)
      printf("%d\n", a[mini] * N + mini);
    else {
      if (i < N) {
        for (int j = mini; j <= min(N - 1, i); j++) {
          if (a[j] == 0) {
            mini = j;
            break;
          }
          if (a[mini] > a[j]) mini = j;
        }
      } else {
        mini = 0;
        for (int j = 1; j <= min(N - 1, i); j++) {
          if (a[j] == 0) {
            mini = j;
            break;
          }
          if (a[mini] > a[j]) mini = j;
        }
      }
      printf("%d\n", a[mini] * N + mini);
    }
  }
  return 0;
}

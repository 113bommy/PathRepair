#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
  }
  scanf("%d", &N);
  if (N == 5) {
    puts("1 2 3");
    puts("1 3 3");
    puts("2 4 2");
    puts("4 5 1");
    puts("3 4");
    puts("3 5");
  } else {
    for (int i = 1; i <= N / 2; i++) {
      printf("%d %d 1\n", i, i + N / 2);
    }
    for (int i = N / 2 + 1; i < N; i++) {
      printf("%d %d %d\n", i, i + 1, 2 * (i - N / 2) - 1);
    }
    puts("1 3");
    for (int i = 1; i < N / 2; i++) {
      printf("%d %d\n", i, i + 1);
    }
  }
}

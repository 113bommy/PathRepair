#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int T, N, M, K;
int p1[MAXN], p2[MAXN];
void insert(int *p, int n, int key);
int main() {
  scanf("%d", &T);
  while (T--) {
    fflush(stdout);
    scanf("%d", &N);
    fill(p1, p1 + 2 * N + 2, 0);
    fill(p2, p2 + 2 * N + 2, 0);
    M = N / 2;
    p1[1] = 1;
    for (int i = 2; i <= M; i++) {
      int key = i;
      int j = i - 1;
      while (j) {
        printf("? %d %d\n", p1[j], key);
        fflush(stdout);
        char op;
        scanf(" %c", &op);
        if (op == '>') break;
        p1[j + 1] = p1[j];
        j--;
      }
      p1[j + 1] = key;
    }
    p2[1] = M + 1;
    for (int i = 2; i + M <= N + 1; i++) {
      int key = i + M;
      int j = i - 1;
      while (j) {
        printf("? %d %d\n", p2[j], key);
        fflush(stdout);
        char op;
        scanf(" %c", &op);
        if (op == '>') break;
        p2[j + 1] = p2[j];
        j--;
      }
      p2[j + 1] = key;
    }
    for (int i = N + 2; i <= 2 * N; i++) {
      printf("? %d %d\n", p1[M], p2[N + 1 - M]);
      fflush(stdout);
      char op;
      scanf(" %c", &op);
      if (op == '>')
        insert(p2, N + 1 - M, i);
      else
        insert(p1, M, i);
    }
    printf("? %d %d\n", p1[M], p2[N + 1 - M]);
    fflush(stdout);
    char op;
    scanf(" %c", &op);
    printf("!\n");
  }
  return 0;
}
void insert(int *p, int n, int key) {
  int j = n;
  while (j) {
    printf("? %d %d\n", p[j], key);
    fflush(stdout);
    char op;
    scanf(" %c", &op);
    if (op == '>') break;
    p[j + 1] = p[j];
    j--;
  }
  p[j + 1] = key;
}

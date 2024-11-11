#include <bits/stdc++.h>
#pragma warning(disable : 4786)
#pragma warning(disable : 4996)
using namespace std;
int n, c;
int A[100], B[100], C[100];
vector<int> V;
int imp = 0;
int Left[105], Right[105];
int solve(int a, int b) {
  if (a > b) return -1;
  if (a == b) {
    Left[a] = Right[a] = -1;
    return a;
  }
  int root = a;
  for (int i = a; i <= b; i++) {
    int now = 1;
    for (int j = 0; j < c; j++) {
      if (A[j] == root) {
        if (C[j] == 0 && !((a + 1) <= (B[j]) && (B[j]) <= (i))) now = 0;
        if (C[j] == 1 && !((i + 1) <= (B[j]) && (B[j]) <= (b))) now = 0;
      } else if (((a + 1) <= (A[j]) && (A[j]) <= (i)) &&
                 ((i + 1) <= (B[j]) && (B[j]) <= (b)))
        now = 0;
    }
    if (now == 0) continue;
    int x = solve(a + 1, i);
    int y = solve(i + 1, b);
    Left[root] = x;
    Right[root] = y;
    return root;
  }
  imp = 1;
  return -1;
}
void inorder(int at) {
  if (at == -1) return;
  inorder(Left[at]);
  V.push_back(at);
  inorder(Right[at]);
}
int main() {
  int i;
  char word[100];
  scanf("%d %d", &n, &c);
  for (i = 0; i < c; i++) {
    scanf("%d %d %s", &A[i], &B[i], word);
    imp |= A[i] >= B[i];
    C[i] = (strcmp(word, "RIGHT") == 0);
  }
  solve(1, n);
  if (imp) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  inorder(1);
  for (i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", V[i]);
  }
  printf("\n");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int INF = 1000000000;
const int MOD = 998244353;
struct Node {
  int a, b, i;
} A[300000], B[300000];
int a = 0, b = 0;
bool cmp(Node& A, Node& B) { return A.a > B.a; }
bool cmp2(Node& A, Node& B) { return A.a < B.a; }
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u < v)
      A[a++] = {a, b, i};
    else
      B[b++] = {a, b, i};
  }
  sort(A, A + a, cmp);
  sort(B, B + b, cmp2);
  if (a > b) {
    printf("%d\n", a);
    for (int i = 0; i < a; i++) {
      printf("%d ", A[i].i + 1);
    }
  } else {
    printf("%d\n", b);
    for (int i = 0; i < b; i++) {
      printf("%d ", B[i].i + 1);
    }
  }
  puts("");
  return 0;
}

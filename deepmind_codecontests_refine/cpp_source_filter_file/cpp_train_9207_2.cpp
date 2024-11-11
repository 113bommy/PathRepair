#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct T {
  int len;
  char S[maxn];
  friend bool operator<(const T &a, const T &b) {
    int ml = min(a.len, b.len);
    for (int i = 1; i <= ml + 1; i++)
      if (a.S[i] != b.S[i]) return a.S[i] < b.S[i];
    return false;
  }
} S1[30][maxn], S2[30][maxn], A;
static int n, L[maxn], L1[maxn], L2[maxn], D1[maxn], D[maxn];
static bool flag;
void out(const T &A, const T &B) {
  if (!flag) printf(", ");
  flag = false;
  for (int i = 0, la = strlen(A.S); i < la; i++) printf("%c", A.S[i]);
  printf(" ");
  for (int i = 0, la = strlen(B.S); i < la; i++) printf("%c", B.S[i]);
}
int main() {
  scanf("%d\n", &n);
  for (int i = 1; i <= n; i++) {
    gets(A.S);
    A.len = strlen(A.S);
    S1[A.S[0] - 'A'][++L1[A.S[0] - 'A']] = A;
  }
  for (int i = 1; i <= n; i++) {
    gets(A.S);
    A.len = strlen(A.S);
    S2[A.S[0] - 'A'][++L2[A.S[0] - 'A']] = A;
  }
  for (int i = 0; i < 26; i++) {
    sort(S1[i] + 1, S1[i] + L1[i] + 1);
    sort(S2[i] + 1, S2[i] + L2[i] + 1);
  }
  int st = 0;
  flag = true;
  for (int Fn = 0; Fn < 26; Fn++) {
    if (L1[Fn] <= L2[Fn]) {
      for (int i = 1; i <= L1[Fn]; i++) {
        D[Fn]++;
        out(S1[Fn][i], S2[Fn][D[Fn]]);
      }
    } else {
      int lef = L1[Fn] - L2[Fn], SS = 0;
      for (int j = 0; j < Fn; j++)
        while (lef != 0 && L2[j] - D[j] - 1 >= L1[j]) {
          lef--;
          SS++;
          D[j]++;
          out(S1[Fn][SS], S2[j][D[j]]);
        }
      for (int j = 1; j <= L2[Fn]; j++) {
        SS++;
        D[Fn]++;
        out(S1[Fn][SS], S2[Fn][D[Fn]]);
      }
      for (int j = Fn; j < 26; j++)
        while (lef != 0 && L2[j] - D[j] - 1 >= L1[j]) {
          lef--;
          SS++;
          D[j]++;
          out(S1[Fn][SS], S2[j][D[j]]);
        }
    }
  }
  printf("\n");
  return 0;
}

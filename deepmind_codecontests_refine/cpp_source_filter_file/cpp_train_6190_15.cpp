#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000 + 1;
char S[MAX_N];
int N, P;
char get(int c) { return c < 0 ? 0 : S[c]; }
bool solve() {
  if (P == 1) return false;
  if (P == 2) {
    if (N == 1) return ++S[0] > 'b';
    if (N == 2) return ++S[0] == 'b' && --S[1] == 'a';
    return false;
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 1; j <= 3; j++) {
      if (get(i) + j <= 'a' + P - 1 && get(i) + j != get(i - 1) &&
          get(i) + j != get(i - 2)) {
        S[i] += j;
        for (int k = i + 1; k < N; k++) {
          for (int c = 0; c < P; c++) {
            if ('a' + c != get(k - 1) && 'a' + c != get(k - 2)) {
              S[k] = 'a' + c;
              break;
            }
          }
        }
        return true;
      }
    }
  }
  return false;
}
int main() {
  while (scanf("%d%d%s", &N, &P, S) != EOF) {
    if (solve())
      printf("YES\n%s\n", S);
    else
      printf("NO\n");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
char S[2000005];
char T[1005][1005];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < (N); ++i) scanf("%s", T[i]);
  for (int i = 0; i < (N); ++i)
    for (int j = 0; j < (N); ++j) T[i][j] -= '0';
  int result = 0;
  int columnChanges[N];
  for (int i = 0; i < (N); ++i) columnChanges[i] = 0;
  for (int i = 0; i < (N); ++i) {
    int change = 0;
    for (int j = N - 1; j > i; j--) {
      T[i][j] ^= change;
      T[i][j] ^= (columnChanges[j] % 2);
      columnChanges[j] ^= T[i][j];
      change ^= T[i][j];
      result += T[i][j];
    }
    T[i][i] ^= change;
  }
  for (int i = 0; i < (N); ++i) T[i][i] ^= columnChanges[i];
  for (int i = 0; i < (N); ++i) columnChanges[i] = 0;
  for (int i = N - 1; i >= 0; i--) {
    int change = 0;
    for (int j = 0; j < i; j++) {
      T[i][j] ^= change;
      T[i][j] ^= (columnChanges[j] % 2);
      columnChanges[j] ^= T[i][j];
      change ^= T[i][j];
      result += T[i][j];
    }
    T[i][i] ^= change;
  }
  for (int i = 0; i < (N); ++i) T[i][i] ^= columnChanges[i];
  for (int i = 0; i < (N); ++i) result += T[i][i];
  printf("%d\n", result);
}

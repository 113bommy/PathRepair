#include <bits/stdc++.h>
using namespace std;
char S[11][101], T[11];
int main() {
  for (int i = 0; i <= 10; i++) cin >> S[i];
  for (int i = 0, j, k; i < 8; i++) {
    k = i * 10;
    for (j = 0; j < 10; j++) T[j] = S[0][k + j];
    for (j = 1; j <= 10; j++)
      if (strcmp(T, S[j]) == 0) cout << j - 1;
  }
  return 0;
}

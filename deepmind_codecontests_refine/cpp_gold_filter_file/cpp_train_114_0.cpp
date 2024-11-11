#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:33554432")
using namespace std;
long long MOD = 1e9 + 7;
int n, k;
int A[5202][5202];
int pref[5202][5202];
bool check(int i, int j, int val) {
  return A[i][j] * val * val == pref[i + val][j + val] + pref[i][j] -
                                    pref[i][j + val] - pref[i + val][j];
}
bool poss(int val) {
  for (int i = 0; i < n; i += val) {
    for (int j = 0; j < n; j += val) {
      if (!check(i, j, val)) return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    char curr;
    for (int j = 0; j < n / 4; j++) {
      scanf("%c", &curr);
      int el = curr > '9' ? curr - 'A' + 10 : curr - '0';
      for (int k = 0; k < 4; k++) {
        A[i][j * 4 + k] = el >= (1 << (3 - k)) ? 1 : 0;
        el -= el >= 1 << (3 - k) ? 1 << (3 - k) : 0;
      }
    }
    scanf("%c", &curr);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] +
                   A[i - 1][j - 1];
  }
  int answer = 1;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0 && poss(i)) answer = i;
  }
  printf("%d", answer);
  return 0;
}

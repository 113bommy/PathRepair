#include <bits/stdc++.h>
using namespace std;
int n;
char S[200001], T[200001];
int ans;
int b, a;
int table[26][26];
int main() {
  int i, j, k, l;
  scanf("%d", &n);
  scanf("%s%s", S, T);
  for (i = 0; i < n; i++) {
    if (S[i] != T[i]) {
      table[S[i] - 'a'][T[i] - 'a']++;
      ans++;
    }
  }
  a = -1;
  b = -1;
  for (i = 0; i < 26; i++) {
    for (j = 0; j < 26; j++) {
      if (table[i][j] > 0 && table[j][i] > 0) {
        printf("%d\n", ans - 2);
        for (l = 0; l < n; l++) {
          if (S[l] == i + 'a' && T[l] == j + 'a' && a == -1) a = l;
          if (S[l] == j + 'a' && T[l] == i + 'a' && b == -1) b = l;
        }
        printf("%d %d\n", min(a, b) + 1, max(a, b) + 1);
        return 0;
      }
    }
  }
  a = -1;
  b = -1;
  for (i = 0; i < 26; i++) {
    for (j = 0; j < 26; j++) {
      for (k = 0; k < 26; k++) {
        if (table[i][j] > 0 && table[j][k] > 0) {
          printf("%d\n", ans - 1);
          for (l = 0; l < n; l++) {
            if (S[l] == i + 'a' && T[l] == j + 'a' && a == -1) a = l;
            if (S[l] == j + 'a' && T[l] == k + 'a' && b == -1) b = l;
          }
          printf("%d %d\n", min(a, b) + 1, max(a, b) + 1);
          return 0;
        }
      }
    }
  }
  printf("%d\n-1 -1\n", ans);
  return 0;
}

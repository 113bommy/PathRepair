#include <bits/stdc++.h>
using namespace std;
int d[5010][5010] = {0};
void check(char *s1, char *s2, int n1, int n2) {
  memset(d, 0, sizeof d);
  for (int i = n1 - 1; i >= 0; i--)
    for (int j = n2 - 1; j >= 0; j--) {
      if (s1[i] == s2[j]) d[i][j] = d[i + 1][j + 1] + 1;
    }
}
int n1, n2;
char s1[5010], s2[5010];
int self1[5010], self2[5010];
int main() {
  scanf("%s %s", s1, s2);
  n1 = strlen(s1);
  n2 = strlen(s2);
  check(s1, s1, n1, n1);
  for (int i = 0; i < n1; i++) {
    self1[i] = 0;
    for (int j = 0; j < n1; j++) {
      if (i != j) self1[i] = max(self1[i], d[i][j] + 1);
    }
    if (self1[i] > n1 - i) self1[i] = 1000000000;
  }
  check(s2, s2, n2, n2);
  for (int i = 0; i < n2; i++) {
    self2[i] = 0;
    for (int j = 0; j < n2; j++) {
      if (i != j) self2[i] = max(self2[i], d[i][j] + 1);
    }
    if (self2[i] > n2 - i) self2[i] = 1000000000;
  }
  check(s1, s2, n1, n2);
  int ans = 1000000000;
  for (int i = 0; i < n1; i++)
    for (int j = 0; j < n2; j++) {
      if (self1[i] <= d[i][j] && self2[j] <= d[i][j])
        ans = min(ans, max(self1[i], self2[j]));
    }
  cout << (ans != 1000000000 ? ans : -1);
  return 0;
}

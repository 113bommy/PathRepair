#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, k, n, p, p1, val, count, j, x;
  char dummy;
  scanf("%d%c", &k, &dummy);
  char c;
  char s[1000];
  scanf("%[^\n]%c", s, &dummy);
  int str[k][strlen(s)];
  int A[k][30];
  for (i = 0; i < strlen(s); i++)
    for (j = 0; j < k; j++) A[j][s[i] - 'a'] = 0;
  for (j = 0; j < k; j++)
    for (i = 0; i < strlen(s); i++) {
      A[j][s[i] - 'a'] += 1;
      str[j][i] = 0;
    }
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %c%c", &p, &c, &dummy);
    p1 = p - 1;
    for (j = 0; j < k; j++) {
      if (p1 >= A[j][c - 'a'])
        p1 -= A[j][c - 'a'];
      else
        break;
    }
    val = j;
    A[val][c - 'a']--;
    count = 0;
    for (j = 0; j < strlen(s); j++) {
      if (s[j] == c && str[val][j] != 1) {
        if (count == p1) {
          str[val][j] = 1;
          break;
        }
        count++;
      }
    }
  }
  for (j = 0; j < k; j++)
    for (i = 0; i < strlen(s); i++)
      if (str[j][i] != 1) printf("%c", s[i]);
  return 0;
}

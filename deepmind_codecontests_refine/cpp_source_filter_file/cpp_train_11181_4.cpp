#include <bits/stdc++.h>
using namespace std;
char s[100005], t[100005], o[100005];
int sl, tl, n;
int p[26][26];
int sum;
void cal() {
  int tsum;
  for (int i = 0; i < sl; i++) {
    if (s[i] == t[i]) {
      o[i] = s[i];
      continue;
    }
    tsum = 0x7fffffff;
    for (int j = 0; j < 26; j++) {
      if (p[s[i] - 'a'][j] != 100000 && p[t[i] - 'a'][j] != 100000) {
        if (p[s[i] - 'a'][j] + p[t[i] - 'a'][j] < tsum) {
          tsum = p[s[i] - 'a'][j] + p[t[i] - 'a'][j];
          o[i] = j + 'a';
        }
      }
    }
    if (tsum == 0x7fffffff) {
      printf("-1");
      return;
    }
    sum += tsum;
  }
  printf("%d\n%s\n", sum, o);
}
int main() {
  scanf("%s%s", s, t);
  sl = strlen(s);
  tl = strlen(t);
  if (sl != tl) {
    printf("-1");
    return 0;
  }
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++)
      if (i != j) p[i][j] = 100000;
  scanf("%d", &n);
  char a[2], b[2];
  int w;
  for (int i = 0; i < n; i++) {
    scanf("%s%s%d", a, b, &w);
    p[a[0] - 'a'][b[0] - 'a'] = min(w, p[a[0] - 'a'][b[0] - 'a']);
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
  cal();
}

#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  static char s[110000], a1[110000], a2[110000];
  int d1[10], d2[10], e1, e2;
  scanf("%s", s);
  int n = strlen(s);
  memset(d1, 0, sizeof(d1));
  for (int i = 0; s[i]; i++) d1[s[i] - '0']++;
  memcpy(d2, d1, sizeof(d1));
  int best = -1, best_d;
  bool found = false;
  int k = 0;
  for (int i = 1; i <= 5; i++) {
    if (d1[i] > 0 && d2[10 - i] > 0) {
      d1[i]--;
      d2[10 - i]--;
      k = 1;
      for (int j = 0; j < 5; j++) k += min(d1[j], d2[9 - j]);
      if (k > best) {
        best = k;
        best_d = i;
        found = true;
      }
      d1[i]++;
      d2[10 - i]++;
    }
  }
  if (found) {
    e1 = '0' + best_d;
    e2 = '0' + (10 - best_d);
    d1[best_d]--;
    d2[10 - best_d]--;
  }
  k = 0;
  for (int i = 0; i < 10; i++) {
    int len = min(d1[i], d2[9 - i]);
    d1[i] -= len;
    d2[9 - i] -= len;
    for (int j = 0; j < len; j++) {
      a1[k] = '0' + i;
      a2[k] = '0' + (9 - i);
      k++;
    }
  }
  if (found) {
    a1[k] = e1;
    a2[k] = e2;
    k++;
  }
  int z = min(d1[0], d2[0]);
  d1[0] -= z;
  d2[0] -= z;
  for (int i = 0; i < z; i++) {
    a1[k] = '0';
    a2[k] = '0';
    k++;
  }
  a1[k] = a2[k] = '\0';
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < d1[i]; j++) printf("%c", i + '0');
  printf("%s\n", a1);
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < d2[i]; j++) printf("%c", i + '0');
  printf("%s\n", a2);
  return 0;
}

#include <bits/stdc++.h>
char line[222];
int diff, ln;
bool marked[222];
int flip(int x) { return ln - 1 - x; }
bool palin() {
  ln = strlen(line);
  for (int i = 0; i < ln; i++) marked[line[i]] = true;
  int x;
  for (int i = (ln - 1) / 2; i >= 0; i--) {
    if (line[i] == '?') {
      if (line[flip(i)] == '?') {
        for (x = diff - 1; x >= 0 && marked[x + 'a']; x--) {
        }
        if (x == -1)
          line[i] = line[flip(i)] = 'a';
        else {
          line[i] = line[flip(i)] = x + 'a';
          marked[x + 'a'] = true;
        }
      } else
        line[i] = line[flip(i)];
    } else if (line[flip(i)] == '?')
      line[flip(i)] = line[i];
    else if (line[i] != line[flip(i)])
      return false;
  }
  for (x = diff - 1; x >= 0 && marked[x + 'a']; x--) {
  }
  return x == -1;
}
int main() {
  scanf("%d %s", &diff, &line);
  if (palin())
    printf("%s\n", line);
  else
    printf("IMPOSSIBLE\n");
  return 0;
}

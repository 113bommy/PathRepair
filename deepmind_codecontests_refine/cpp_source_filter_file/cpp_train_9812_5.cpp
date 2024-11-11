#include <bits/stdc++.h>
using namespace std;
pair<int, int> d[10], t[10];
int sd(int i, int j) {
  return (d[i].first - d[j].first) * (d[i].first - d[j].first) +
         (d[i].second - d[j].second) * (d[i].second - d[j].second);
}
bool sq() {
  int a = sd(0, 1);
  int b = sd(1, 2);
  int c = sd(2, 3);
  int d = sd(3, 0);
  int ac = sd(0, 2);
  int bd = sd(1, 3);
  return a + b == ac && c + d == ac && a == c && b == d && a == b && ac == bd;
}
bool rect() {
  int a = sd(4, 5);
  int b = sd(5, 6);
  int c = sd(6, 7);
  int d = sd(7, 4);
  int ac = sd(4, 6);
  return a + b == ac && c + d == ac && a == c && b == d;
}
int main() {
  int i, j;
  for (i = 0; i < 8; i++) {
    scanf("%d %d", &d[i].first, &d[i].second);
    t[i] = d[i];
  }
  sort(d, d + 8);
  bool f = 0;
  do {
    if (sq() && rect()) {
      f = 1;
      break;
    }
  } while (next_permutation(d, d + 8));
  if (!f) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 8; j++)
      if (d[i] == t[j]) break;
    printf(i ? " %d" : "%d", j);
  }
  puts("");
  for (i = 4; i < 8; i++) {
    for (j = 0; j < 8; j++)
      if (d[i] == t[j]) break;
    printf(i == 4 ? "%d" : " %d", j);
  }
  puts("");
  return 0;
}

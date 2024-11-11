#include <bits/stdc++.h>
bool vis[3][3] = {};
int ops[3][3] = {};
enum compare { EQUAL, LITTLE, BIG };
void process() {
  char t[20];
  scanf("%s", t);
  int a = t[0] - 'A';
  int b = t[2] - 'A';
  int op = t[1];
  if (a == b || vis[a][b]) {
    puts("Impossible");
    exit(0);
  }
  vis[a][b] = vis[b][a] = true;
  ops[a][b] = op == '>' ? BIG : LITTLE;
  ops[b][a] = op == '>' ? LITTLE : BIG;
}
int main() {
  process();
  process();
  process();
  int p[] = {0, 1, 2};
  do {
    int a = p[0], b = p[1], c = p[2];
    if (ops[a][b] == LITTLE && ops[b][c] == LITTLE && ops[a][c] == LITTLE) {
      char A = a + 'A', B = b + 'A', C = c + 'A';
      printf("%c%c%c\n", A, B, C);
      return 0;
    }
  } while (std::next_permutation(p, p + 3));
  puts("Impossible");
  return 0;
}

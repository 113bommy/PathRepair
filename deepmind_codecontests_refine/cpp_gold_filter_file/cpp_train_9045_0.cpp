#include <cstdio>

using namespace std;

const int nil = -1;
const int MAX_N = 256;

struct Node {
  int l, r, cnt;
  Node() {
    l = r = nil;
    cnt = 0;
  }
};

Node v[MAX_N];
int nodeIndex;

int parse(const char *s, int n, int root) {
  v[root].cnt++;
  if (s[++n] != ',') {
    if (v[root].l == nil) v[root].l = ++nodeIndex;
    n = parse(s, n, v[root].l);
  }
  if (s[++n] != ')') {
    if (v[root].r == nil) v[root].r = ++nodeIndex;
    n = parse(s, n, v[root].r);
  }
  return n+1;
}

void print(int root, int cnt) {
  if (v[root].cnt < cnt) return;
  putchar('(');
  if (v[root].l != nil) print(v[root].l, cnt);
  putchar(',');
  if (v[root].r != nil) print(v[root].r, cnt);
  putchar(')');
}

int main() {
  char op[5], t1[1024], t2[1024];
  while (scanf("%s %s %s", op, t1, t2) == 3) {
    for (int i=0;i<MAX_N;i++) v[i] = Node();
    nodeIndex = 0;
    parse(t1, 0, 0);
    parse(t2, 0, 0);
    print(0, (op[0]=='u'?1:2)); putchar('\n');
  }
  return 0;
}
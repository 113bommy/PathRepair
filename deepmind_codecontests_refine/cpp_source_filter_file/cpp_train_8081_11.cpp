#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
char S[500005], T[500005], A[MAXN];
struct Node {
  int len;
  int seriesAns;
  int seriesPre;
  Node *link, *slink;
  map<int, Node *> to;
  Node(int _len) : len(_len) {}
  int diff() { return len > 0 ? len - link->len : 0; }
};
int pos;
Node *last, *zero;
void init() {
  Node *neg1 = new Node(-1);
  zero = new Node(0);
  neg1->link = neg1->slink = neg1;
  zero->link = zero->slink = neg1;
  last = neg1;
  pos = 0;
}
Node *getLink(Node *v) {
  while (pos == v->len || A[pos - v->len - 1] != A[pos]) v = v->link;
  return v;
}
void addLetter() {
  char c = A[pos];
  last = getLink(last);
  if (!last->to[c]) {
    Node *node = new Node(last->len + 2);
    node->link = getLink(last->link)->to[c];
    if (!node->link) node->link = zero;
    if (node->diff() == node->link->diff()) {
      node->slink = node->link->slink;
    } else {
      node->slink = node->link;
    }
    last->to[c] = node;
  }
  last = last->to[c];
  ++pos;
}
const int INF = 1000000000;
int ans[MAXN], pre[MAXN];
int main() {
  scanf("%s%s", S, T);
  int m = strlen(S), n = 0;
  for (int i = 0; i < m; ++i) {
    A[n++] = S[i];
    A[n++] = T[i];
  }
  init();
  memset(pre, -1, sizeof(pre));
  for (int i = 1; i <= n; ++i) {
    ans[i] = INF;
    if (i >= 2 && A[i - 1] == A[i - 2]) ans[i] = ans[i - 2];
    addLetter();
    for (Node *x = last; x->len > 0; x = x->slink) {
      x->seriesAns = INF;
      if (!((x->slink->len + x->diff()) & 1)) {
        x->seriesAns = ans[i - x->slink->len - x->diff()];
        x->seriesPre = i - x->slink->len - x->diff();
      }
      if (x->slink != x->link) {
        if (x->link->seriesAns < x->seriesAns) {
          x->seriesAns = x->link->seriesAns;
          x->seriesPre = x->link->seriesPre;
        }
      }
      if (x->seriesAns + 1 < ans[i]) {
        ans[i] = x->seriesAns + 1;
        pre[i] = x->seriesPre;
      }
    }
  }
  if (ans[n] > n) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", ans[n]);
  for (int i = n; i;) {
    if (pre[i] == -1) {
      i -= 2;
    } else {
      printf("%d %d\n", (pre[i] + 2) / 2, i / 2);
      i = pre[i];
    }
  }
}

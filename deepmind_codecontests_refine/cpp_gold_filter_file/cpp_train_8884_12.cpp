#include <bits/stdc++.h>
using namespace std;
template <class T>
void checkmin(T &t, T x) {
  if (x < t) t = x;
}
template <class T>
void checkmax(T &t, T x) {
  if (x > t) t = x;
}
template <class T>
void _checkmin(T &t, T x) {
  if (t == -1) t = x;
  if (x < t) t = x;
}
template <class T>
void _checkmax(T &t, T x) {
  if (t == -1) t = x;
  if (x > t) t = x;
}
const int N = 1000005;
int n, m;
int op[N];
char s[N];
stack<int> sk;
struct Node {
  Node *l, *r;
  char c;
  bool f[2][2];
} Tr[N], *root;
void gao(Node *&p, int l, int r) {
  while (op[l] == r) {
    l++;
    r--;
  }
  p = &Tr[m++];
  memset(p->f, 0, sizeof(p->f));
  if (l == r) {
    if (s[l] == '?') {
      p->f[0][1] = 1;
      p->f[1][0] = 1;
    } else if (s[l] == '0') {
      p->f[0][0] = 1;
    } else {
      p->f[1][1] = 1;
    }
    p->l = p->r = NULL;
  } else {
    char c;
    if (s[l] == '(') {
      gao(p->l, l, op[l]);
      c = s[op[l] + 1];
    } else {
      gao(p->l, l, l);
      c = s[l + 1];
    }
    if (s[r] == ')') {
      gao(p->r, op[r], r);
    } else {
      gao(p->r, r, r);
    }
    if (c == '&') {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          for (int k = 0; k < 2; k++) {
            for (int l = 0; l < 2; l++) {
              if (p->l->f[i][j] && p->r->f[k][l]) {
                p->f[i & k][j & l] = 1;
              }
            }
          }
        }
      }
    } else if (c == '|') {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          for (int k = 0; k < 2; k++) {
            for (int l = 0; l < 2; l++) {
              if (p->l->f[i][j] && p->r->f[k][l]) {
                p->f[i | k][j | l] = 1;
              }
            }
          }
        }
      }
    } else if (c == '^') {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          for (int k = 0; k < 2; k++) {
            for (int l = 0; l < 2; l++) {
              if (p->l->f[i][j] && p->r->f[k][l]) {
                p->f[i ^ k][j ^ l] = 1;
              }
            }
          }
        }
      }
    }
  }
}
int main() {
  memset(op, 0xFF, sizeof(op));
  scanf("%d", &n);
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      sk.push(i);
    } else if (s[i] == ')') {
      op[sk.top()] = i;
      op[i] = sk.top();
      sk.pop();
    }
  }
  m = 0;
  gao(root, 0, n - 1);
  if (root->f[0][1] || root->f[1][0]) {
    puts("YES");
  } else {
    puts("NO");
  }
}

#include <bits/stdc++.h>
using namespace std;
struct node {
  char c;
  int ji;
  int index;
} tree[205];
int n;
char s[204];
node te;
bool cmp(node a, node b) { return a.index < b.index; }
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    tree[i].c = s[i];
    tree[i].ji = -1;
    tree[i].index = i;
  }
  sort(s + 1, s + n + 1);
  for (int i = 1; i <= n; i++) {
    if (tree[i].c == s[1]) {
      tree[i].ji = 1;
      for (int j = 1; j < i; j++) {
        tree[j].ji = 0;
      }
      for (int j = i - 1; j >= 1; j--) {
        te = tree[j];
        tree[j] = tree[j + 1];
        tree[j + 1] = te;
      }
      break;
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (s[i] == tree[j].c) {
        if (i == j) {
          if (tree[i].ji == -1) {
            tree[i].ji = 1 - tree[i - 1].ji;
          }
        } else {
          if (tree[i].ji == -1) {
            tree[j].ji = 1;
            for (int k = i; k < j; k++) {
              tree[k].ji = 0;
            }
            for (int k = j - 1; k >= i; k--) {
              te = tree[k];
              tree[k] = tree[k + 1];
              tree[k + 1] = te;
            }
          } else {
            for (int k = i; k < j; k++) {
              if (tree[k].ji != -1 && tree[k].ji != tree[i].ji) {
                cout << "NO";
                return 0;
              }
              tree[k].ji = tree[i].ji;
            }
            if (tree[j].ji == tree[i].ji) {
              cout << "NO";
              return 0;
            }
            tree[j].ji = 1 - tree[j - 1].ji;
            for (int k = j - 1; k >= i; k--) {
              te = tree[k];
              tree[k] = tree[k + 1];
              tree[k + 1] = te;
            }
          }
        }
        break;
      }
    }
  }
  sort(tree + 1, tree + n + 1, cmp);
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    printf("%d", tree[i].ji);
  }
}

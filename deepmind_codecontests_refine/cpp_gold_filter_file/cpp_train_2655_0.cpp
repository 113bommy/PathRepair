#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
int mm[maxn];
struct node {
  bool flag;
  int size;
};
bool vis1[maxn];
bool vis[maxn];
int main() {
  int n;
  scanf("%d", &n);
  int i, j, k;
  for (i = 1; i <= n; i++) {
    scanf("%d", &mm[i]);
  }
  memset(vis, true, sizeof(vis));
  memset(vis1, true, sizeof(vis1));
  node A, B;
  A.flag = true;
  A.size = 1;
  B.size = 1;
  B.flag = false;
  int m1 = 0;
  while (A.size <= n) {
    if (m1 % 2 == 0) {
      for (i = 1; i <= n; i++) {
        if (vis[i] && mm[i] < A.size) {
          vis[i] = false;
          A.size++;
        }
      }
    } else {
      for (i = n; i > 0; i--) {
        if (vis[i] && mm[i] < A.size) {
          vis[i] = false;
          A.size++;
        }
      }
    }
    m1++;
  }
  int m2 = 0;
  while (B.size <= n) {
    if (m2 % 2 == 1) {
      for (i = 1; i <= n; i++) {
        if (vis1[i] && mm[i] < B.size) {
          vis1[i] = false;
          B.size++;
        }
      }
    } else {
      for (i = n; i > 0; i--) {
        if (vis1[i] && mm[i] < B.size) {
          vis1[i] = false;
          B.size++;
        }
      }
    }
    m2++;
  }
  printf("%d\n", m1 - 1);
  return 0;
}

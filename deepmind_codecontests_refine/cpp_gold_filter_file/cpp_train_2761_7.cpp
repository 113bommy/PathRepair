#include <bits/stdc++.h>
using namespace std;
int presold[(200001)];
int postsold[(200001)];
int preprod[(200001)];
int postprod[(200001)];
int n;
void push(int pos, int val, int* arr) {
  while (pos <= n) {
    arr[pos] += val;
    pos += (pos & (-pos));
  }
  return;
}
int find(int pos, int* arr) {
  int ret = 0;
  while (pos > 0) {
    ret += arr[pos];
    pos -= pos & (-pos);
  }
  return ret;
}
int main() {
  int k, a, b, q;
  scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
  for (int i = 1; i <= n; i++) {
    preprod[i] = b;
    postprod[i] = a;
  }
  for (int i = 0; i < q; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int pos, val;
      scanf("%d %d", &pos, &val);
      if (preprod[pos] >= val) {
        preprod[pos] -= val;
        push(pos, val, presold);
      } else {
        push(pos, preprod[pos], presold);
        preprod[pos] = 0;
      }
      if (postprod[pos] >= val) {
        postprod[pos] -= val;
        push(pos, val, postsold);
      } else {
        push(pos, postprod[pos], postsold);
        postprod[pos] = 0;
      }
    } else {
      int pos;
      scanf("%d", &pos);
      int ans = find(pos - 1, presold) + find(n, postsold) -
                find(pos + k - 1, postsold);
      printf("%d\n", ans);
    }
  }
  return 0;
}

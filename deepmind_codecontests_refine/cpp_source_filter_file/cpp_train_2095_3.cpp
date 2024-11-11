#include <bits/stdc++.h>
using namespace std;
int data[200030], pos[200030];
typedef struct node {
  int val, pos;
  int tsl;
} Node;
Node ans[200030];
int main() {
  int left = 0, right = 0, n, m, cnt = 0;
  cin >> n >> m;
  for (int i = 0; i < n + m; i++) scanf("%d", &pos[i]);
  for (int i = 0; i < n + m; i++) {
    scanf("%d", &data[i]);
    if (data[i] == 1) {
      ans[cnt].pos = i;
      ans[cnt++].val = pos[i];
    }
  }
  for (int i = 1; i < cnt; i++) {
    left = i - 1;
    right = i;
    int mid = (ans[left].val + ans[right].val) / 2;
    for (int j = ans[left].pos + 1; j < ans[right].pos; j++) {
      if (ans[j].val <= mid) {
        ans[left].tsl++;
      } else
        ans[right].tsl++;
    }
  }
  ans[0].tsl += ans[0].pos;
  ans[cnt - 1].tsl += n + m - ans[cnt - 1].pos - 1;
  for (int i = 0; i < cnt; i++) printf("%d ", ans[i].tsl);
  return 0;
}

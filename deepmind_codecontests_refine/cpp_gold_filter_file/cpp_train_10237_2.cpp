#include <bits/stdc++.h>
using namespace std;
map<int, int> op;
vector<long long> v[110000];
int n;
int cnt[110000];
int tot;
struct node {
  int c, id;
  long long s;
} cube[110000];
struct node MAX[110000][2];
int sel[2][2];
int path[110000];
bool cmp(node A, node B) { return (A.c == B.c) ? (A.s > B.s) : (A.c < B.c); }
int main() {
  long long ans = 0;
  int C;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cube[i].id = i;
    scanf("%d%I64d", &cube[i].c, &cube[i].s);
  }
  sort(cube + 1, cube + 1 + n, cmp);
  for (int i = 1; i <= n; i++) MAX[i][0].s = MAX[i][1].s = -1000000000000000LL;
  for (int i = 1; i <= n; i++) {
    if (op[cube[i].c] == 0) op[cube[i].c] = ++tot;
    C = op[cube[i].c];
    if (cnt[C] == 0)
      v[C].push_back(cube[i].s);
    else
      v[C].push_back(v[C][cnt[C] - 1] + cube[i].s);
    cnt[C]++;
    if (v[C][cnt[C] - 1] >= MAX[cnt[C]][0].s) {
      MAX[cnt[C]][1] = MAX[cnt[C]][0];
      MAX[cnt[C]][0].s = v[C][cnt[C] - 1];
      MAX[cnt[C]][0].c = C;
    } else if (v[C][cnt[C] - 1] > MAX[cnt[C]][1].s) {
      MAX[cnt[C]][1].s = v[C][cnt[C] - 1];
      MAX[cnt[C]][1].c = C;
    }
  }
  for (int i = 2; i <= n; i++)
    if (i % 2 == 0) {
      if (MAX[i / 2][0].s + MAX[i / 2][1].s > ans) {
        ans = MAX[i / 2][0].s + MAX[i / 2][1].s;
        sel[0][0] = MAX[i / 2][0].c;
        sel[1][0] = MAX[i / 2][1].c;
        sel[0][1] = i / 2;
        sel[1][1] = i / 2;
      }
    } else {
      if (MAX[i / 2 + 1][0].c == MAX[i / 2][0].c &&
          MAX[i / 2 + 1][0].s + MAX[i / 2][1].s > ans) {
        ans = MAX[i / 2 + 1][0].s + MAX[i / 2][1].s;
        sel[0][1] = i / 2 + 1;
        sel[1][1] = i / 2;
        sel[0][0] = MAX[i / 2 + 1][0].c;
        sel[1][0] = MAX[i / 2][1].c;
      }
      if (MAX[i / 2 + 1][0].c == MAX[i / 2][0].c &&
          MAX[i / 2][0].s + MAX[i / 2 + 1][1].s > ans) {
        ans = MAX[i / 2][0].s + MAX[i / 2 + 1][1].s;
        sel[0][1] = i / 2 + 1;
        sel[1][1] = i / 2;
        sel[0][0] = MAX[i / 2 + 1][1].c;
        sel[1][0] = MAX[i / 2][0].c;
      } else if (MAX[i / 2 + 1][0].c != MAX[i / 2][0].c &&
                 MAX[i / 2 + 1][0].s + MAX[i / 2][0].s > ans) {
        ans = MAX[i / 2 + 1][0].s + MAX[i / 2][0].s;
        sel[0][1] = i / 2 + 1;
        sel[1][1] = i / 2;
        sel[0][0] = MAX[i / 2 + 1][0].c;
        sel[1][0] = MAX[i / 2][0].c;
      }
    }
  printf("%I64d\n", ans);
  printf("%d\n", sel[0][1] + sel[1][1]);
  int p, q;
  for (p = 1; p <= n; p++)
    if (op[cube[p].c] == sel[0][0]) break;
  for (q = 1; q <= n; q++)
    if (op[cube[q].c] == sel[1][0]) break;
  for (int i = 1; i <= sel[1][1]; i++)
    printf("%d %d ", cube[p + i - 1].id, cube[q + i - 1].id);
  if (sel[0][1] > sel[1][1])
    printf("%d\n", cube[p + sel[0][1] - 1].id);
  else
    printf("\n");
  return 0;
}
